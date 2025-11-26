// ConveyorBeltCapacityCheck
// Checks if inputted number of motors can carry inputted weight of packages.
#include <stdio.h>

// Defining relevant variables.
// Initializes motorCapacity to 5.6, as each motor can carry that weight in kg.
double motorCount;
double motorCapacity = 5.6;
double totalPackageWeight;

// Prompts the user for inputting the number of motors and total package weight.
// Displays an error if the user inputs the wrong datatype, such as a char.
// Calculates if the inputted number of motors can carry the packages.
int main(void) {
  printf("How many motors will be carrying the packages?\n");

  // Defines an integer which is 1 if the input
  // from scanf is of the correct datatype.
  int validMotorCountInput = scanf("%lf", &motorCount);

  // Checks if the user has inputted the correct datatype.
  if (validMotorCountInput == 1) {
    printf("What is the total weight of the packages?\n");

    // Defines an integer which is 1 of the input
    // from scanf is of the correct datatype.
    int validPackageWeightInput = scanf("%lf", &totalPackageWeight);

    // Checks if the user has inputted the correct datatype and calculates
    // the ratio between package weight and how much the motors can carry.
    if (validPackageWeightInput == 1 &&
        totalPackageWeight / motorCount <= motorCapacity) {
      printf("The motors can carry the packages!✅");
      // If the datatype is correct, but the motors can't carry the packages.
    } else if (validPackageWeightInput == 1 &&
               totalPackageWeight / motorCount > motorCapacity) {
      printf("The motors cannot carry the packages!❌");
      // If none of the above are true, then the datatype must be incorrect.
    } else {
      printf("Error: wrong data format inputted!🫤");
    }
    // If none of the above are true, then the datatype must be incorrect.
  } else {
    printf("Error: wrong data format inputted!");
  }
}
/*
Første strofer: beskriver forklarende kommentarer og globale variablerne i toppen:
motorCapacity = 5.6 (hver motor kan bære 5.6 kg),
motorCount og totalPackageWeight (de globale double-variabler).
Mellemsektionen: beskriver inputdelen i main:
Først prompt: "How many motors..." og scanf("%lf", &motorCount).
Validering af input via validMotorCountInput.
Andet prompt: "What is the total weight..." og scanf("%lf", &totalPackageWeight).
Beregning og betingelser:
Hvis begge scanf lykkes og totalPackageWeight / motorCount <= motorCapacity → succes (print med ✅).
Hvis begge scanf lykkes men ratio > motorCapacity → fiasko (print med ❌).
Ellers (scanf-fejl) → fejlmeddelelse "Error: wrong data format inputted!".
Afsluttende linje: programmet returnerer implicit 0 (ingen eksplicit return i main).
Vigtige kanttilfælde og bemærkninger
Division med nul: hvis brugeren indtaster 0 for motorCount, vil totalPackageWeight / motorCount medføre division-by-zero (UB) — programmet håndterer det ikke i dag.
Negative tal: programmet accepterer negative input — logisk men måske upraktisk (negativ motorantal eller negativ vægt). Overvej at validere for positive værdier.
Scanf-format: programmet bruger "%lf" og gemmer i globale double — men tjekkene ser kun efter returværdien 1. Hvis brugeren indtaster fx "3a", scanf kan læse 3 og efterlade tegn; overvej at rydde input-buffer eller bruge bedre input-håndtering.
Global state: motorCount og totalPackageWeight er globale; til en lille øvelse er det fint, men lokale variabler i main er ofte at foretrække.
Små, lavrisiko forbedringer (forslag)
Beskyt mod division med nul:
Tjek if (motorCount == 0) og vis en venlig fejl ("Motor count cannot be zero").
Kræv positive værdier:
Tjek if (motorCount <= 0 || totalPackageWeight < 0) og giv passende fejl.
Lokaliser variabler:
Flyt motorCount og totalPackageWeight ind i main (fjern globals) for bedre indkapsling.
Bedre input-rensning:
Brug fgets+strtod eller lignende for robust parsing og håndtering af ugyldige linjer.
Tilføj ny linje efter printf-udskrifter for pænere terminaloutput (fx printf("...✅\n");).
*/