/** \brief Suma dos numeros float.
 *
 * \param float primer miembro de la suma.
 * \param float segundo miembro de la suma.
 * \return float resultado de la suma.
 *
 */
float suma(float numeroA, float numeroB)
{
    float resultado=0.0;
    resultado=numeroA+numeroB;
    return resultado;
}


/** \brief Resta dos numeros float.
 *
 * \param float primer miembro de la resta.
 * \param float segundo miembro de la resta.
 * \return float resultado de la operaci�n.
 *
 */
float resta(float numeroA, float numeroB)
{
    float resultado=0.0;
    resultado=numeroA-numeroB;
    return resultado;
}


/** \brief Realiza el cociente entre dos n�meros float.
 *
 * \param float divisor.
 * \param float dividendo.
 * \return float resultado del cociente.
 *
 */
float cociente(float numeroA, float numeroB)
{
    float resultado=0.0;
    if(numeroB!=0)
    {
        resultado=numeroA/numeroB;
    }
    return resultado;
}


/** \brief Calcula el producto de dos n�meros float
 *
 * \param float primer miembro del producto.
 * \param float segundo miembro del producto.
 * \return float resultado del producto.
 *
 */
float producto(float numeroA, float numeroB)
{
    float resultado=0.0;
    resultado=numeroA*numeroB;
    return resultado;
}


/** \brief Calcula el factorial de un n�mero entero
 *
 * \param numero (int) es el n�mero al que se le v� a calcular el factorial
 * \return el resultado del factorial
 *
 */
int factorial(int numero)
{
    if(numero==1) //Si el numero es 1, se devuelve el factorial de 1 (1).
    {
        return 1;
    }
    else{ //Sino se calcula el factorial del numero-1 y lo multiplico por el numero (recursividad)
        return ( numero * factorial(numero-1) );
    }
}
