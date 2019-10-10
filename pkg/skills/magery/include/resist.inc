use uo;
//should get target mr
//should get target int
//shoulg get caster magery
//should get caster eval
//should get caster int
// the resist calc should include all above in it's formula
// intelligence has height 3
// caster mage has height 4
// caster eval has height 3
// castOn rs has height 6
// add a random dice roll of 5dimensions 3 numbers each hdimension;
// add it to MR , if the result is bigger then the sum of caster stats
// added to a roll 2d 2 numbers dice then resist
//parms[1] = caster
//parms[2] = target
//parms[3] = spellHardness
function ResistSpell(parms)
  var caster := dictionary {
    "char" -> parms[1],
    "mage" -> CInt(GetAttribute(parms[1], MAGERY)),
    "eval" -> CInt(GetAttribute(parms[1], EVALUATING_INTELLIGENCE)),
    "int" -> CInt(GetAttribute(parms[1], ATTRIBUTEID_INTELLIGENCE))
  };
  var castOn := dictionary {
    "char" -> parms[2],
    "resist" -> CInt(GetAttribute(parms[2], RESISTING_SPELLS)),
    "int" -> CInt(GetAttribute(parms[2], ATTRIBUTEID_INTELLIGENCE))
  };
  var spellHardness := parms[3];

  if(castOn.char.dead)
    return 0;
  endif
  var resisterStats := (castOn.resist) - spellHardness + RandomDiceRoll("9d4") + randomInt(spellHardness/5);
  var casterStats := ((caster.mage*50)/100) + ((caster.eval*20)/100)  + RandomDiceRoll("9d4") - randomInt(spellHardness/4);

//result of resist spell should be not integer
//result should amortize the dmg of the spell based on resisterStats - casterStats
  if (resisterStats > casterStats)
    return 1;
  else
    return 0;
  endif
endfunction
