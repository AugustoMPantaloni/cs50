import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        database = list(reader)

    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    str_counts = {}
    for subsequence in database[0][1:]:
        str_counts[subsequence] = longest_match(sequence, subsequence)

    target = [str_counts[subsequence] for subsequence in database[0][1:]]
    for person in database[1:]:
        name = person[0]
        values = list(map(int, person[1:]))

        if values == target:
            print(name)
            return

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Devuelve la longitud de la secuencia más larga del subsequence dentro de sequence."""

    # Inicializar variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Verificar cada carácter en la secuencia para encontrar la mayor cantidad de repeticiones consecutivas del subsequence
    for i in range(sequence_length):

        # Inicializar el contador de repeticiones consecutivas
        count = 0

        # Verificar si hay una coincidencia del subsequence en una "subcadena" (un subconjunto de caracteres) dentro de la secuencia
        # Si hay coincidencia, mover la subcadena a la siguiente posible coincidencia en la secuencia
        # Continuar moviendo la subcadena y verificando coincidencias hasta que no haya más coincidencias consecutivas
        while True:

            # Ajustar el inicio y fin de la subcadena
            start = i + count * subsequence_length
            end = start + subsequence_length

            # Si hay coincidencia en la subcadena
            if sequence[start:end] == subsequence:
                count += 1

            # Si no hay coincidencia en la subcadena
            else:
                break

        # Actualizar el mayor número de coincidencias consecutivas encontradas
        longest_run = max(longest_run, count)

    # Luego de revisar todas las posiciones en la secuencia, devolver la mayor cantidad de repeticiones consecutivas encontradas
    return longest_run


main()
