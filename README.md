# cpf\_plygnd
A simple generator and validator for cpf numbers.
As a check if the program works we can cross validate against [freetool.dev](https://www.freetool.dev/cpf-generator-validator).
The structure and maths behind a cpf are found [on this portuguese
site](http://clubes.obmep.org.br/blog/a-matematica-nos-documentos-cpf/)

The project intends to get used as a starter into whatever idea comes up.
The initial version shows a bad implementation with deterministic randomness.

# ideas
- get a timebased seed and show why this is the same stupid idea as using the preseederd ,randomness'
- get some randomness out of /dev/random to seed the rng
- work out how the age of a person counts into the cpf

# storage
[validator](https://www.freetool.dev/cpf-generator-validator)<br>
[structure](http://clubes.obmep.org.br/blog/a-matematica-nos-documentos-cpf/)
