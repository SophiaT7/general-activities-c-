/*Escolheria a lista encadeada, ja que os elementos nao precisam estar em um vetor mas sim em
qualquer lugar mas voa se ligar atraves de indices, ponteiros que os ligam, podendo ser acessados
de maneira simplificada.
Se houver insercao no inicio/fim da lista - o(1)
mas para acessar o ultimo deve-se percorrer tudo se tive o indice sera o(1);
Se houver remocao comeco/fim - o(1) se ja tiver indice, se nao sea o(n);
Se houver acesso aleatorio sera o(n), esse tipo de lista nao permite acesso direto por indice, logo
seu tempo de acesso é o(n), pois e necessario acessar um por um;
na mioria das op e necessario realizar busca o(n) para realizar a op.

porem nesse tipo de lista a insercao e remocao sao rapido e possui uso dinamico pois n esta
em um vetor, assim nao possui tam maximo. */
