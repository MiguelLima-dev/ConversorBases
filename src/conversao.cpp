#include "conversao.hpp"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// DECIMAL → BINÁRIO
string deci_bin(double decimal, bool trace) {
    string binario = "";
    int parte_inteira = decimal;
    double parte_fracionaria = decimal - parte_inteira;

    if (trace) cout << "\n=== Decimal → Binário ===" << endl;
    if (trace) cout << "\n-- Parte inteira (divisões sucessivas) --" << endl;

    if (parte_inteira == 0) binario = "0";

    while (parte_inteira != 0) {
        int resto = parte_inteira % 2;
        if (trace)
            cout << parte_inteira << " ÷ 2 = " << parte_inteira / 2
                 << "  resto " << resto << endl;
        binario = char(resto + '0') + binario;
        parte_inteira /= 2;
    }

    if (trace) cout << "Lendo restos de baixo para cima: " << binario << endl;

    if (parte_fracionaria > 1e-12) {
        binario += '.';
        if (trace) cout << "\n-- Parte fracionária (multiplicações sucessivas) --" << endl;

        int casas = 16;
        string frac = "";
        while (parte_fracionaria > 1e-12 && casas-- > 0) {
            parte_fracionaria *= 2;
            int digito = (int)parte_fracionaria;
            if (trace)
                cout << "X 2 = " << parte_fracionaria
                     << "  → dígito " << digito << endl;
            frac += char(digito + '0');
            parte_fracionaria -= digito;
        }
        binario += frac;

        if (parte_fracionaria > 1e-12) {
            binario += "[...]";
            if (trace) cout << "(truncado em 16 casas)" << endl;
        }
        if (trace) cout << "Parte fracionária: " << frac << endl;
    }

    return binario;
}

// DECIMAL → OCTAL
string deci_oct(double decimal, bool trace) {
    string octal = "";
    int parte_inteira = decimal;
    double parte_fracionaria = decimal - parte_inteira;

    if (trace) cout << "\n=== Decimal → Octal ===" << endl;
    if (trace) cout << "\n-- Parte inteira (divisões sucessivas) --" << endl;

    if (parte_inteira == 0) octal = "0";

    while (parte_inteira != 0) {
        int resto = parte_inteira % 8;
        if (trace)
            cout << parte_inteira << " ÷ 8 = " << parte_inteira / 8
                 << "  resto " << resto << endl;
        octal = char(resto + '0') + octal;
        parte_inteira /= 8;
    }

    if (trace) cout << "Lendo restos de baixo para cima: " << octal << endl;

    if (parte_fracionaria > 1e-12) {
        octal += '.';
        if (trace) cout << "\n-- Parte fracionária (multiplicações sucessivas) --" << endl;

        int casas = 16;
        string frac = "";
        while (parte_fracionaria > 1e-12 && casas-- > 0) {
            parte_fracionaria *= 8;
            int digito = (int)parte_fracionaria;
            if (trace)
                cout << "X 8 = " << parte_fracionaria
                     << "  → dígito " << digito << endl;
            frac += char(digito + '0');
            parte_fracionaria -= digito;
        }
        octal += frac;

        if (parte_fracionaria > 1e-12) {
            octal += "[...]";
            if (trace) cout << "(truncado em 16 casas)" << endl;
        }
        if (trace) cout << "Parte fracionária: " << frac << endl;
    }

    return octal;
}

// DECIMAL → HEXADECIMAL
string deci_hexa(double decimal, bool trace) {
    string hexadecimal = "";
    int parte_inteira = decimal;
    double parte_fracionaria = decimal - parte_inteira;
    string digitos = "0123456789ABCDEF";

    if (trace) cout << "\n=== Decimal → Hexadecimal ===" << endl;
    if (trace) cout << "\n-- Parte inteira (divisões sucessivas) --" << endl;

    if (parte_inteira == 0) hexadecimal = "0";

    while (parte_inteira != 0) {
        int resto = parte_inteira % 16;
        if (trace)
            cout << parte_inteira << " ÷ 16 = " << parte_inteira / 16
                 << "  resto " << resto << " (" << digitos[resto] << ")" << endl;
        hexadecimal = digitos[resto] + hexadecimal;
        parte_inteira /= 16;
    }

    if (trace) cout << "Lendo restos de baixo para cima: " << hexadecimal << endl;

    if (parte_fracionaria > 1e-12) {
        hexadecimal += '.';
        if (trace) cout << "\n-- Parte fracionária (multiplicações sucessivas) --" << endl;

        int casas = 16;
        string frac = "";
        while (parte_fracionaria > 1e-12 && casas-- > 0) {
            parte_fracionaria *= 16;
            int digito = (int)parte_fracionaria;
            if (trace)
                cout << "X 16 = " << parte_fracionaria
                     << "  → dígito " << digitos[digito] << endl;
            frac += digitos[digito];
            parte_fracionaria -= digito;
        }
        hexadecimal += frac;

        if (parte_fracionaria > 1e-12) {
            hexadecimal += "[...]";
            if (trace) cout << "(truncado em 16 casas)" << endl;
        }
        if (trace) cout << "Parte fracionária: " << frac << endl;
    }

    return hexadecimal;
}

// AUXILIAR: índice do dígito hex
int index(char c) {
    string digitos = "0123456789ABCDEF";
    char maiusculo = toupper((unsigned char)c);
    for (int i = 0; i < 16; i++)
        if (digitos[i] == maiusculo) return i;
    return -1;
}

// BINÁRIO → DECIMAL
int bin_deci(string binario, bool trace) {
    int decimal = 0, peso = 1;
    int n = binario.length();

    if (trace) {
        cout << "\n=== Binário → Decimal ===" << endl;
        cout << "\n-- Somatório posicional --" << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = binario[i] - '0';
        int contribuicao = digito * peso;
        if (trace)
            cout << digito << " X 2^" << (n-1-i) << " = " << contribuicao << endl;
        decimal += contribuicao;
        peso *= 2;
    }

    if (trace) cout << "Soma total: " << decimal << endl;
    return decimal;
}

// PARTE FRACIONÁRIA BINÁRIA → DECIMAL
double binFrac_deci(string fracao, bool trace) {
    double resultado = 0.0;
    double peso = 0.5;

    if (trace) cout << "\n-- Parte fracionária binária → decimal --" << endl;

    for (int i = 0; fracao[i] != '\0'; i++) {
        int digito = fracao[i] - '0';
        double contribuicao = digito * peso;
        if (trace)
            cout << digito << " X 2^-" << (i+1) << " = " << contribuicao << endl;
        resultado += contribuicao;
        peso /= 2.0;
    }

    if (trace) cout << "Soma fracionária: " << resultado << endl;
    return resultado;
}

// OCTAL → DECIMAL
int oct_deci(string octal, bool trace) {
    int decimal = 0, peso = 1;
    int n = octal.length();

    if (trace) {
        cout << "\n=== Octal → Decimal ===" << endl;
        cout << "\n-- Somatório posicional --" << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = octal[i] - '0';
        int contribuicao = digito * peso;
        if (trace)
            cout << digito << " X 8^" << (n-1-i) << " = " << contribuicao << endl;
        decimal += contribuicao;
        peso *= 8;
    }

    if (trace) cout << "Soma total: " << decimal << endl;
    return decimal;
}

// PARTE FRACIONÁRIA OCTAL → DECIMAL
double octFrac_deci(string fracao, bool trace) {
    double resultado = 0.0;
    double peso = 1.0 / 8.0;

    if (trace) cout << "\n-- Parte fracionária octal → decimal --" << endl;

    for (int i = 0; fracao[i] != '\0'; i++) {
        int digito = fracao[i] - '0';
        double contribuicao = digito * peso;
        if (trace)
            cout << digito << " X  8^-" << (i+1) << " = " << contribuicao << endl;
        resultado += contribuicao;
        peso /= 8.0;
    }

    if (trace) cout << "Soma fracionária: " << resultado << endl;
    return resultado;
}

// HEXADECIMAL → DECIMAL
int hexa_deci(string hexadecimal, bool trace) {
    int decimal = 0, peso = 1;
    int n = hexadecimal.length();

    if (trace) {
        cout << "\n=== Hexadecimal → Decimal ===" << endl;
        cout << "\n-- Somatório posicional --" << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = index(hexadecimal[i]);
        int contribuicao = digito * peso;
        if (trace)
            cout << hexadecimal[i] << "(" << digito << ")"
                 << " X 16^" << (n-1-i) << " = " << contribuicao << endl;
        decimal += contribuicao;
        peso *= 16;
    }

    if (trace) cout << "Soma total: " << decimal << endl;
    return decimal;
}

// PARTE FRACIONÁRIA HEXADECIMAL → DECIMAL
double hexaFrac_deci(string fracao, bool trace) {
    double resultado = 0.0;
    double peso = 1.0 / 16.0;

    if (trace) cout << "\n-- Parte fracionária hexadecimal → decimal --" << endl;

    for (int i = 0; fracao[i] != '\0'; i++) {
        int digito = index(fracao[i]);
        double contribuicao = digito * peso;
        if (trace)
            cout << fracao[i] << "(" << digito << ")"
                 << " X 16^-" << (i+1) << " = " << contribuicao << endl;
        resultado += contribuicao;
        peso /= 16.0;
    }

    if (trace) cout << "Soma fracionária: " << resultado << endl;
    return resultado;
}

// AUXILIARES: tabelas de agrupamento
char conversao(string blocoOCT) {
    if (blocoOCT == "000") return '0';
    if (blocoOCT == "001") return '1';
    if (blocoOCT == "010") return '2';
    if (blocoOCT == "011") return '3';
    if (blocoOCT == "100") return '4';
    if (blocoOCT == "101") return '5';
    if (blocoOCT == "110") return '6';
    if (blocoOCT == "111") return '7';
    return '0';
}

string inversao(char caractere) {
    if (caractere == '0') return "000";
    if (caractere == '1') return "001";
    if (caractere == '2') return "010";
    if (caractere == '3') return "011";
    if (caractere == '4') return "100";
    if (caractere == '5') return "101";
    if (caractere == '6') return "110";
    if (caractere == '7') return "111";
    return "";
}

char conversaoH(string blocoHEX) {
    if (blocoHEX == "0000") return '0';
    if (blocoHEX == "0001") return '1';
    if (blocoHEX == "0010") return '2';
    if (blocoHEX == "0011") return '3';
    if (blocoHEX == "0100") return '4';
    if (blocoHEX == "0101") return '5';
    if (blocoHEX == "0110") return '6';
    if (blocoHEX == "0111") return '7';
    if (blocoHEX == "1000") return '8';
    if (blocoHEX == "1001") return '9';
    if (blocoHEX == "1010") return 'A';
    if (blocoHEX == "1011") return 'B';
    if (blocoHEX == "1100") return 'C';
    if (blocoHEX == "1101") return 'D';
    if (blocoHEX == "1110") return 'E';
    if (blocoHEX == "1111") return 'F';
    return '0';
}

string inversaoH(char caractere) {
    char c = toupper((unsigned char)caractere);
    if (c == '0') return "0000";
    if (c == '1') return "0001";
    if (c == '2') return "0010";
    if (c == '3') return "0011";
    if (c == '4') return "0100";
    if (c == '5') return "0101";
    if (c == '6') return "0110";
    if (c == '7') return "0111";
    if (c == '8') return "1000";
    if (c == '9') return "1001";
    if (c == 'A') return "1010";
    if (c == 'B') return "1011";
    if (c == 'C') return "1100";
    if (c == 'D') return "1101";
    if (c == 'E') return "1110";
    if (c == 'F') return "1111";
    return "";
}

// BINÁRIO → OCTAL
string bin_oct(string binario, bool trace) {
    string inteira, fracionaria;
    separa(binario, inteira, fracionaria);

    int tam = inteira.length();
    if      (tam % 3 == 1) inteira = "00" + inteira;
    else if (tam % 3 == 2) inteira = "0"  + inteira;

    if (trace) {
        cout << "\n=== Binário → Octal ===" << endl;
        cout << "Parte inteira com padding: " << inteira << endl;
        cout << "\n-- Agrupamento de 3 bits --" << endl;
    }

    string result = "";
    for (int i = 0; i < (int)inteira.length(); i += 3) {
        string bloco = inteira.substr(i, 3);
        char digito = conversao(bloco);
        if (trace)
            cout << bloco << " → " << digito << endl;
        result += digito;
    }

    if (fracionaria != "") {
        tam = fracionaria.length();
        if      (tam % 3 == 1) fracionaria += "00";
        else if (tam % 3 == 2) fracionaria += "0";

        if (trace) cout << "\n-- Agrupamento de 3 bits (parte fracionária) --" << endl;
        
        result += ".";
        for (int i = 0; i < (int)fracionaria.length(); i += 3) {
            string bloco = fracionaria.substr(i, 3);
            char digito = conversao(bloco);
            if (trace) cout << bloco << " → " << digito << endl;
            result += digito;
        }
    }
    if (trace) cout << "Resultado: " << result << endl;
    return result;
}

// OCTAL → BINÁRIO
string oct_bin(string octal, bool trace) {
    string inteira, fracionaria;
    separa(octal, inteira, fracionaria);

    if (trace) {
        cout << "\n=== Octal → Binário ===" << endl;
        cout << "\n-- Expansão de cada dígito em 3 bits (parte inteira) --" << endl;
    }

    string result = "";
    for (int i = 0; i < (int)inteira.length(); i++) {
        string bits = inversao(inteira[i]);
        if (trace)
            cout << inteira[i] << " → " << bits << endl;
        result += bits;
    }

    if (fracionaria != "") {
        if (trace) cout << "\n-- Expansão de cada digito em 3 bits (parte fracionária) --" << endl;
        
        result += ".";
        for (int i = 0; i < (int)fracionaria.length(); i++) {
            string bits = inversao(fracionaria[i]);
            if (trace) cout << fracionaria[i] << " → " << bits << endl;
            result += bits;
        }
    }

    if (trace) cout << "Resultado: " << result << endl;
    return result;
}

// BINÁRIO → HEXADECIMAL
string bin_hexa(string binario, bool trace) {
    string inteira, fracionaria;
    separa(binario, inteira, fracionaria);

    int tam = inteira.length();
    if      (tam % 4 == 1) inteira = "000" + inteira;
    else if (tam % 4 == 2) inteira = "00"  + inteira;
    else if (tam % 4 == 3) inteira = "0"   + inteira;

    if (trace) {
        cout << "\n=== Binário → Hexadecimal ===" << endl;
        cout << "Parte inteira com padding: " << inteira << endl;
        cout << "\n-- Agrupamento de 4 bits --" << endl;
    }

    string result = "";
    for (int i = 0; i < (int)inteira.length(); i += 4) {
        string bloco = inteira.substr(i, 4);
        char digito = conversaoH(bloco);
        if (trace)
            cout << bloco << " → " << digito << endl;
        result += digito;
    }

    if (fracionaria != "") {
        tam = fracionaria.length();
        if      (tam % 4 == 1) fracionaria += "000";
        else if (tam % 4 == 2) fracionaria += "00";
        else if (tam % 4 == 3) fracionaria += "0";

        if (trace) cout << "\n-- Agrupamento de 4 bits (parte fracionária) --" << endl;

        result += ".";
        for (int i = 0; i < (int)fracionaria.length(); i += 4) {
            string bloco = fracionaria.substr(i, 4);
            char digito = conversaoH(bloco);
            if (trace) cout << bloco << " → " << digito << endl;
            result += digito;
        }
    }

    if (trace) cout << "Resultado: " << result << endl;
    return result;
}

// HEXADECIMAL → BINÁRIO
string hexa_bin(string hexadecimal, bool trace) {
    string inteira, fracionaria;
    separa(hexadecimal, inteira, fracionaria);

    string binario_inteira = "";
    if (trace) {
        cout << "\n=== Hexadecimal → Binário ===" << endl;
        cout << "\n-- Expansão de cada dígito em 4 bits (parte inteira) --" << endl;
    }

    for (int i = 0; i < (int)inteira.length(); i++) {
        string bits = inversaoH(inteira[i]);
        if (trace) cout << inteira[i] << " → " << bits << endl;
        binario_inteira += bits;
    }

    // AJUSTE DINÂMICO PARA COMPRIMENTO DE PALAVRA HEXA:
    // Se a entrada hex contiver 2 caracteres como "10", gera 8 bits.
    // Se a entrada contiver 1 caractere como "A", gera 4 bits originalmente.
    // Os testes exigem que tanto "10" quanto "A.8" preencham múltiplos estritos de 8 bits na saída de hexa_bin.
    int n_blocos = (inteira.length() + 1) / 2; 
    int tam_esperado = n_blocos * 8;
    while ((int)binario_inteira.length() < tam_esperado) {
        binario_inteira = "0000" + binario_inteira;
    }

    string resultado_final = binario_inteira;

    if (fracionaria != "") {
        if (trace) cout << "\n-- Expansão de cada dígito em 4 bits (parte fracionária) --" << endl;
        resultado_final += ".";
        for (int i = 0; i < (int)fracionaria.length(); i++) {
            string bits = inversaoH(fracionaria[i]);
            if (trace) cout << fracionaria[i] << " → " << bits << endl;
            resultado_final += bits;
        }
    }

    if (trace) cout << "Resultado: " << resultado_final << endl;
    return resultado_final;
}

// LÓGICA DE LIMPEZA GERAL DE ZEROS EXCEDENTES (Para saídas compostas inter-bases)
string limpa_zeros(string str) {
    string int_p, frac_p;
    separa(str, int_p, frac_p);

    // Limpa zeros à esquerda da parte inteira, mantendo ao menos um "0"
    int i = 0;
    while (i < (int)int_p.length() - 1 && int_p[i] == '0') {
        i++;
    }
    int_p = int_p.substr(i);

    // Limpa zeros à direita da parte fracionária
    if (!frac_p.empty()) {
        int j = frac_p.length() - 1;
        while (j >= 0 && frac_p[j] == '0') {
            j--;
        }
        if (j >= 0) {
            frac_p = frac_p.substr(0, j + 1);
            return int_p + "." + frac_p;
        } else {
            return int_p; // Virou inteiro puro
        }
    }
    return int_p;
}

// OCTAL → HEXADECIMAL (via binário)
string oct_hexa(string octal, bool trace) {
    if (trace) cout << "\n=== Octal → Hexadecimal (via Binário) ===" << endl;
    string binario = oct_bin(octal, trace);
    string hexadecimal = bin_hexa(binario, trace);
    string resultado = limpa_zeros(hexadecimal);
    if (trace) cout << "Resultado final limpo: " << resultado << endl;
    return resultado;
}

// HEXADECIMAL → OCTAL (via binário)
string hexa_oct(string hexadecimal, bool trace) {
    if (trace) cout << "\n=== Hexadecimal → Octal (via Binário) ===" << endl;
    string binario = hexa_bin(hexadecimal, trace);
    string octal = bin_oct(binario, trace);
    string resultado = limpa_zeros(octal);
    if (trace) cout << "Resultado final limpo: " << resultado << endl;
    return resultado;
}