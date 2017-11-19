/**
 * Created by oscar on 19/11/2017.
 */

function WrongTypeException(message)
{
    this.message = message
    this.name    = 'NotIntException'

}

function VertexNotIdentifiedException(intVal)
{
    this.message = intVal + " vertex not identified"
    this.name    = 'VertexNotIdentifiedException'

}

function isPositiveInteger (input)
{
    if ($.isNumeric(input))

        if(Math.floor(input) !== input)
            throw new WrongTypeException("Value not positive integer");

        else
            return true;

    throw new NotIntException();

}

function isArray(input)
{
    if (input instanceof Array)
        return true

    throw new WrongTypeException("Value not array");

}

function getKeys(inArray)
{

    if (isArray(inArray))

        var keys = Object.keys(inArray)

        return $.map(keys, function (val) {
            return parseInt(val)
        })

}