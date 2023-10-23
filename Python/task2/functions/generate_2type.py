def generate(data, type1, type2, arr_type1, arr_type2):
    new_data = {}
    for character1 in arr_type1:
        for character2 in arr_type2:
            new_data[(character1, character2)] = data[(data[type1] == character1) & (data[type2] == character2)].values
    return new_data

