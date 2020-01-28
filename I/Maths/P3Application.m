function [a] = P3Application()
%Transport de l'information par porteuse

% Variables
a=0;                                % Code retour de la fonction
T=50;                               % Intervalle temporel de mesure
N=16384;                            % Nombre de points
f1=40;                              % Fréquence de la porteuse #1
f2=60;                              % Fréquence de la porteuse #2
Xa=(-T/2):(T/N):(T/2)-(T/N);        % Abscisse Temporelle
X=(-N/(2*T)):(1/T):(N/(2*T))-(1/T); % Abscisse Frequentielle
S1=zeros(1,16384);                  % Signal à transmettre #1
S2=zeros(1,16384);                  % Signal à transmettre #2
C=zeros(1,16384);                   % Signal résultat AM
D1=zeros(1,16384);                  % Signal décrypté #1
D2=zeros(1,16384);                  % Signal décrypté #2
E1=zeros(1,16384);                  % Signal décrypté filtré #1
E2=zeros(1,16384);                  % Signal décrypté filtré #1

% Création des signaux
for i=1:4
    for j=1:16384
        b=Xa(j);
        S1(j)=S1(j)+(i*cos(2*pi*i*b));
        S2(j)=S2(j)+((5-i)*cos(2*pi*i*b));
    end
end

% Modulation et démodulation du signal
for i=1:16384
    C(i)=S1(i)*cos(2*pi*f1*Xa(i))+S2(i)*cos(2*pi*f2*Xa(i));
    D1(i)=C(i)*cos(2*pi*f1*Xa(i));
    D2(i)=C(i)*cos(2*pi*f2*Xa(i));
end

% Filtre passe bas
E1=tfour(D1);
E2=tfour(D2);

for i=1:16384
    if abs(X(i))>8
        E1(i)=0;
        E2(i)=0;
    end
end

% Affichage de toutes les fonctions
figure('numbertitle','off','name','Signal #1');
plot (X, tfour(S1));
figure('numbertitle','off','name','Signal #2');
plot (X, tfour(S2));
figure('numbertitle','off','name','Signal Transmis AM');
plot (X, tfour(C));
figure('numbertitle','off','name','Signal décrypté #1');
plot (X, tfour(D1));
figure('numbertitle','off','name','Signal décrypté #2');
plot (X, tfour(D2));
figure('numbertitle','off','name','Signal décrypté et filtré #1');
plot (X, E1);
figure('numbertitle','off','name','Signal décrypté et filtré #2');
plot (X, E2);

end
