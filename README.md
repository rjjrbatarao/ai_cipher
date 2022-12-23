# AI Cipher
AI Cipher is a proof of concept cipher I've developed to incorporate artificial intelligence on encryption as well as compression on a sigle shot. The algorithm is very basic on the encryption phase where valid words are encrypted using a simple character subsititution 0 - 9 or any unique character to match. The AI comes into play on decoding the words where 2d array of characters are generated and the encrypted word will be one of the combinations of the array ie. 

## Todo
 * still solving the code for combination algorithm with dynamic arrays.

```
numberic_table = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
word: my
encrypted to a number: 91

decoder will produce: ['cmw','eoy']
total comninations: 9
array size: 2

combinations:
ce, mo, wy, we, co, my, me, wo, cy

one of the combination will be the encrypted word.
valid words:
we, my, me

AI will be used to get the valid words.
Then the on the resulting array AI will construct a valid sentence.

```
## Cons
```
* slow
* only possible with valid words, sentences or phrases.
* security might be low
```

## Pros
```
* a cipher algorithm compression with encryption of atmost 50% reduction are possible. ie (my)2 bytes are encoded into a 1 byte number 91.
* many possibilities can be made which only future can tell.
* ai trainable decryption can be made.
```
