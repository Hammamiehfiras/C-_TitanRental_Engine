Projekt1: Teknisk sammanfattning:Titan Rental Engine

Detta system är en modulär C++-applikation för hantering av fordonsflottor, uppdelad i 20 filer för optimal struktur. Projektet demonstrerar avancerad användning av:

    OOP-arkitektur: Använder arv och polymorfism (genom den abstrakta basklassen Vehicle) för att hantera olika fordonstyper och deras specifika prisberäkningar vid körning.

    Designmönster: Implementerar Singleton för en centraliserad Logger-klass.

    Algoritmer & Datastrukturer: * Sortering: Använder std::sort med Lambda-uttryck (O(nlogn)) för prisoptimering.

        Geofencing: Sökalgoritm som beräknar euklidiskt avstånd mellan koordinater.

        Erase-Remove: Effektiv radering av objekt ur std::vector.

    Data Persistence (CRUD): Fullständig hantering av Create, Read, Update, Delete med filinläsning/skrivning via fstream.

    Robusthet: Inmatningshantering med std::getline och anpassad felhantering via RentalException.
