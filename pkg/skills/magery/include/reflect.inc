include "include/client";
include "include/sounds";

//should get caster reflect
//should get cast_on reflecct
//each splash of magic cost some portion of mr to reflect
//if both have the same mr, it should randomly assign who receives the damage
//if caster mr is bigger than cast_on mr, cast_or is target
//caster is the target otherwise
//each splash should cost some amount of reflect on the target.
//target can be caster or castOn, depending on which splash we are


//should get objProperty 'mr'
//should check if it is bigger then costToReflect and return a true or false;
//parms[1] is splash target
//parms[2] is the mrRequire
function hasEnoughtReflect( parms )
  var targetMR := CInt(GetobjProperty(parms[1], "mr"));
  if (!mrRequired)
     mrRequired := parms[2];
  endif
  return targetMR >= mrRequired;
endfunction

//should check if currentChecking have enoughtReflect, if yes, currentCheccking becomes nextTarget
//and nextTarget becomes currentChecking
function iterateTargets( parms )
  var currentChecking := parms[1];
  var nextTarget := parms[2];
  if (!hasEnoughtReflect({ currentChecking }))
    return currentChecking;
  else
    PlaySoundEffect(currentChecking, SFX_SPELL_MAGIC_REFLECTION);
    PlayObjectCenteredEffect(currentChecking, FX_CURSE_EFFECT, 10,10);
    SendSysMessage(currentChecking, "Sua Aura Anti Magia Lhe Protege",9,89);
    sleepms(timeDelay);
    if (spellEffect == "LIGHTNINGBOLT" )
      PlayLightningBoltEffect(nextTarget);
    else
      PlayMovingEffect( currentChecking, nextTarget, spellEffect, 5, 1 );
    endif
    PlaySoundEffect( currentChecking, spellSound );
    SetObjProperty(currentChecking, "delayreflect", ReadGameClock() + 80);
    SetobjProperty(currentChecking, "mr", CInt(GetobjProperty(currentChecking, "mr")) - mrRequired);
    return iterateTargets({ nextTarget, currentChecking });
  endif
endfunction
///parm 1 = caster
//parm 2 = cast_on
//parm 3 = mrRequired
//parm 4 = spellEffect
//parm 5 = spellSound
//parm 6 = timeDelay
var mrRequired, spellEffect, spellSound, timeDelay;
function reflectSpell( parms )
  var caster := parms[1];
  var castOn := parms[2];
  mrRequired := parms[3];
  spellEffect := parms[4];
  spellSound := parms[5];
  timeDelay := parms[6];
  //should check if target has enought mr to reflect that, if not, just move forward, as when 30 is remaining we might want to reflect an arrow.
  //should iterate until castOn or caster have no MR
  return iterateTargets({ castOn, caster });
endfunction
