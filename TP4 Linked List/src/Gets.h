#ifndef GETS_H_INCLUDED
#define GETS_H_INCLUDED

#endif // GETS_H_INCLUDED

/** \brief Validates that the user can enter only letters
 *
 * \param string[] char array of letters
 * \return int Return (-1) if Error [Invalid character(s)] - (0) if Ok
 *
 */
int validateString(char string[]);


/** \brief Validates that the user can enter only integer numbers
 *
 * \param string[] char array of numbers
 * \return int Return (-1) if Error [Invalid character(s)] - (0) if Ok
 *
 */
int validateInt(char string[]);


/** \brief Validates that the user can enter only float numbers
 *
 * \param string[] char array of numbers
 * \return int Return (-1) if Error [Invalid character(s)] - (0) if Ok
 *
 */
int validateFloat(char string[]);


/** \brief Ask the user to input an integer
 *
 * \param min int minimum value accepted
 * \param max int maximum value accepted
 * \param message[] char Text that ask for the data
 * \return int Return the input number
 *
 */
int getInt(int min, int max, char message[]);


/** \brief Ask the user to input a float
 *
 * \param min float minimum value accepted
 * \param max float maximum value accepted
 * \param message[] char Text that ask for the data
 * \return float Return the input number
 *
 */
float getFloat(float min, float max, char message[]);


/** \brief Ask the user to input a character
 *
 * \param message[] char Text that ask for the data
 * \return char Return the input letter
 *
 */
char getChar(char message[]);


/** \brief Ask the user to input an array of character
 *
 * \param string[] char array of characters
 * \param min int minimum of letters
 * \param max int maximum of letters
 * \param message[] char Text that ask for the data
 * \return void
 *
 */
void getString(char string[], int min, int max, char message[]);
