# Dados Públicos de CNPJ - Receita Federal


Requerimentos:
- wget
- gcc


```bash
git clone https://github.com/melchisedech333/dados-publicos-cnpj.git
cd dados-publicos-cnpj
chmod +x links.sh
gcc downloader.c -o downloader -lpthread
./downloader 
```


