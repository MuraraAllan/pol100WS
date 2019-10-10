use uo;
use os;


function dmg(attacker, weapon)
var dano;
var armalumber:=0;

case(weapon.graphic)
 //error:	dano:=RandomInt(3); 	  		///wrestling
 3936:	dano:=RandomInt(16) + 13;  		///Espada Longa
 5042:	dano:=RandomInt(13) + RandomInt(5) + 18;		///ARCO
 3919:	dano:=RandomInt(15) + RandomInt(5) + 22;		///BESTA
 5117:	dano:=RandomInt(14) + RandomInt(5) + 24;		///BESTA PESADA
 5039:	dano:=RandomInt(23) + 15; armalumber:=1; ///MACHADO DE GUERRA
 3913:  dano:=RandomInt(23) + 15; armalumber:=1;	///MACHADO
 3911:	dano:=RandomInt(23) + 15; armalumber:=1;	///MACHADINHO
 3915:  dano:=RandomInt(23) + 15; armalumber:=1; ///MACHADO DUPLO
 3909:  dano:=RandomInt(23) + 15; armalumber:=1;	 ///MACHADO DO CARRASCO
 5114:  dano:=RandomInt(23) + 15; armalumber:=1;  ///MACHADO DE BATALHA
 5186:  dano:=RandomInt(23) + 15; armalumber:=1;  ///MACHADO DE DUAS MAOS
 5122:  dano:=RandomInt(13) + RandomInt(5) + 12;		 ///LAN�A PEQUENA
 3939:  dano:=RandomInt(15) + RandomInt(8) + 10;		 ///LAN�A GRANDE
 3918:  dano:=RandomInt(20) + RandomInt(5) + 23;		 ///BARDICHE
 5182:  dano:=RandomInt(20) + RandomInt(5) + 23;		 ///ALABARDA
 3932:	dano:=RandomInt(20) + 5;		 ///MACA
 5178:  dano:=RandomInt(25) + 12;		 ///MACA LONGA
 5180:  dano:=RandomInt(15) + 7;		 ///MARRETA
 5176:  dano:=RandomInt(20) + RandomInt(8) + 11;		 ///MARTELO DE GUERRA
 5126:  dano:=RandomInt(27) + 20;		 ///MACA DE GUERRA
 5124:  dano:=RandomInt(20) + 13;		 ///GARFO DE GUERRA
 3934:  dano:=RandomInt(20) + 12;		 ///ESPADA LARGA
 5184:  dano:=RandomInt(21) + 10;		 ///CUTELO (ARMA MENOR Q KATANA)
 3921:  dano:=RandomInt(4) + 3;			 ///ADAGA
 5118:  dano:=RandomInt(15) + 9;			 ///KATANA
 5121:  dano:=RandomInt(15) + 9;			 ///KOPESH
 5049:  dano:=RandomInt(20) + RandomInt(8) + 15;			 ///BASTARDA
 5045:  dano:=RandomInt(20) + 11;			 ///CIMITARRA
 3717:  dano:=RandomInt(6) + 2;			 ///PICARETA
 5110:  dano:=RandomInt(4) + 2;			 ///PUNHAL
 3778:  dano:=RandomInt(8) + 2;			 ///FACA A�OUGUEIRO
 5043:  dano:=RandomInt(8) + 14;			 ///PORRETE
 3719:  dano:=RandomInt(26) + 6;			 ///TRIDENTE
 3568:  dano:=RandomInt(11) + 13;			 ///CAJADO NEGRO
 5113:  dano:=RandomInt(11) + 10;			 ///CAJADO TORCIDO
 3713:  dano:=RandomInt(11) + 9;			 ///CAJADO DO PASTOR
 3722:  dano:=RandomInt(11) + 11;			 ///BASTAO
endcase


if(armalumber == 1)
  dano := dano - randomdiceroll("1d5") + cint(GetEffectiveSkill(attacker, SKILLID_TACTICS) / 15) + cint(GetEffectiveSkill(attacker, SKILLID_ANATOMY) / 25) + randomint(cint(GetEffectiveSkill(attacker, SKILLID_LUMBERJACKING) / 20) )+cint(GetEffectiveSkill(attacker, SKILLID_LUMBERJACKING) / 50) + 3;
else

dano := dano - randomdiceroll("1d5") + cint(GetEffectiveSkill(attacker, SKILLID_TACTICS) / 15) + cint(GetEffectiveSkill(attacker, SKILLID_ANATOMY) / 25);
endif

return dano;

endfunction
