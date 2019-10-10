use uo;
use os;
use util;

include ":magery:reflect";
include ":magery:resist";

function CheckLostFocus( parms )
  var prevtime := parms[1];
  var caster := parms[2];
  if(Readgameclock() >=  prevtime)
    SendSysMessage(caster, "Voce demorou demais e perdeu o focus",9,90);
    PlayStationaryEffect( caster.x, caster.y, caster.z, FX_SMOKE, 0xa, 0xa );
    playSoundEffect(caster,0x005d);
    setmana(caster, Getmana(caster) + 4);
    return 1;
  endif
endfunction

function useMana ( who, mana ) 
  var subractVital := AP_ConsumeVital(who, VITALID_MANA, mana);
  if (!subractVital) 
    return 0;
  endif 
  return 1;
endfunction
