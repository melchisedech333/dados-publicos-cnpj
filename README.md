# Dados Públicos de CNPJ - Receita Federal

Por algum motivo os arquivos de dados públicos de CNPJ, ao serem baixados, o são em uma velocidade muito lenta, em muitos casos chegam a travar o download, ao ponto de ter que recomeçar tudo novamente. Esta aplicação resolve este problema, a mesma realiza os downloads normalmente, mas a cada 3 minutos eles são reiniciados (mas sempre continuando da parte em que estavam). Desta maneira você pode baixar os dados públicos sem complicações.


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


