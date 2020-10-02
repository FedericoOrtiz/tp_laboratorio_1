#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief to indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list array of employees
* \param length int Array size
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int length);


/** \brief find an empty space in the array
* \param list array of employees
* \param length int Array size
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int findSpace(Employee list[], int length);


/** \brief upload the employee's information
* \param list array of employees
* \param length int Array size
* \param id int auto generated id
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int createEmployee(Employee list[], int length, int id);


/** \brief add a new employee to the system
* \param list array of employees
* \param length int Array size
* \param id int auto generated id
* \param name string received name
* \param lastName string received last name
* \param salary float received salary
* \param sector int received sector
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee list[], int length, int id, char name[], char lastName[], float salary, int sector);


/** \brief find an Employee by Id en returns the index position in array.
* \param list array of employees
* \param length int Array size
* \param id int received id
* \return int Return employee index position or (-1) Error [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee list[], int length, int id);


/** \brief modify employee's information
 *
 * \param list array of employees
 * \param length int Array size
 * \param id int received id
 *
 */
void modifyEmployee(Employee list[], int length, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list array of employees
* \param length int Array size
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] or the user doesn't confirm - (0) if Ok
*
*/
int removeEmployee(Employee list[], int length, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
* \param list array of employees
* \param length int Array size
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (0)
*
*/
int sortEmployees(Employee list[], int length, int order);

/** \brief print the content of an employee
* \param anEmployee information of the employee
*
*/
void printEmployee(Employee anEmployee);

/** \brief print the content of employees array
* \param list array of employees
* \param length int Array size
* \return int Return (0)
*
*/
int printEmployees(Employee list[], int length);


