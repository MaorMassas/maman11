#include <stdio.h>
#include <ctype.h>

int main() {
    int c;                       /* תו קלט נוכחי */
    int in_quotes = 0;           /* דגל המציין אם אנחנו בתוך מרכאות */
    int start_of_sentence = 1;   /* דגל המציין אם אנחנו בתחילת משפט */

    printf("Please enter your text (end input with EOF):\n");

    while ((c = getchar()) != EOF) {
        if (c == '"') {
            in_quotes = !in_quotes; /* מתחלף בין מרכאות */
            putchar(c);
        } else if (in_quotes) {
            /* בתו בתוך מרכאות */
            if (islower(c)) {
                putchar(toupper(c)); /* אות קטנה למרכאות נהפכת לגדולה */
            } else {
                putchar(c);
            }
        } else if (start_of_sentence) {
            /* התחל משפט */
            if (islower(c)) {
                putchar(toupper(c)); /* אות קטנה בתחילת משפט נהפכת לגדולה */
                start_of_sentence = 0;
            } else if (!isspace(c)) {
                start_of_sentence = 0;
                if (isupper(c)) {
                    putchar(tolower(c)); /* אות גדולה (אם אינה בתחילת משפט) נהפכת לקטנה */
                } else if (!isdigit(c)) {
                    putchar(c); /* שאר תווים ללא שינוי */
                }
            } else {
                putchar(c); /* תווים לבנים נשמרים */
            }
        } else {
            /* תו באמצע טקסט */
            if (c == '.') {
                start_of_sentence = 1; /* סימן נקודה מסמן את סוף המשפט */
            }
            if (isupper(c)) {
                putchar(tolower(c)); /* אות גדולה נהפכת לקטנה */
            } else if (!isdigit(c)) {
                putchar(c); /* תווים אחרים נשמרים */
            }
        }
    }
    return 0;
}
