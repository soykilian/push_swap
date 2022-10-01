import random
a_list = (random.sample(range(0, 600), 500))
converted_list = [str(element) for element in a_list]
print(" ".join(converted_list))
