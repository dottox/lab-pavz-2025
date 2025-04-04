#pragma once

/*
  @brief Enum representing the time of day for classes.

  The Turno enum defines three possible time slots for classes:
  - Manana: Morning
  - Tarde: Afternoon
  - Noche: Night
  Each value corresponds to a specific time of day when classes can be scheduled.
  This enum is used to categorize classes based on their scheduled time,
  allowing for better organization and management of class schedules.
  @note The values of the enum are not explicitly defined, but they are
  automatically assigned starting from 0. The first value (Manana) will be 0,
  the second value (Tarde) will be 1, and the third value (Noche) will be 2.
  @warning Ensure that the values of the enum are used consistently throughout
  the codebase to avoid confusion. The enum values should be used in
  conjunction with the Clase class to determine the time slot for each class.
  @see Clase
*/
enum Turno{
    Manana,
    Tarde,
    Noche
};
