import math
"""
Sieve of Eratothenes
"""
def sieve(n):
	"""yield prime numbers up to n"""
	if n < 2:
		return []
	else:
		is_prime = [True] * n
		is_prime[0] = is_prime[1] = False
		for i in range(2, n):
			if is_prime[i]:
				yield i
				for num in range(i*i, n, i):
					is_prime[num] = False

def sieve_verbose(n):
	"""Generate a list of prime numbers up to n"""
	if n < 2:
		return []
	else:
		is_prime = [True] * n
		is_prime[0] = is_prime[1] = False
		
		for i in range(2, math.floor(math.sqrt(n))):
			if is_prime[i]:
				print("{} is prime".format(i))
				print("Removing multiples of {}:".format(i))
				removed = []
				for num in range(i*i, n, i):
					is_prime[num] = False
					removed.append(num)
				print(removed)

		primes = []
		for i in range(2, len(is_prime)):
			if is_prime[i]:
				primes.append(i)
		return primes

size = 120
primes = sieve_verbose(size)
print("Prime numbers up to {}:".format(size))
print(primes)
