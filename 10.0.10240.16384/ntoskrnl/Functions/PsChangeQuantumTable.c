// PsChangeQuantumTable 
 
int __fastcall PsChangeQuantumTable(int result, char a2)
{
  unsigned int v2; // r2
  int v4; // r7
  __int16 *v5; // r4

  v2 = a2 & 3;
  v4 = result;
  if ( v2 >= 2 )
    v2 = 2;
  PsPrioritySeparation = v2;
  if ( (a2 & 0xC) != 4 && ((a2 & 0xC) == 8 || (result = MmIsThisAnNtAsSystem()) != 0) )
    v5 = &PspFixedQuantums;
  else
    v5 = &PspVariableQuantums;
  if ( (a2 & 0x30) == 16 || (a2 & 0x30) != 32 && (result = MmIsThisAnNtAsSystem()) != 0 )
    v5 = (__int16 *)((char *)v5 + 3);
  PspUseJobSchedulingClasses = v5 == &word_8C74D7;
  PspForegroundQuantum = *v5;
  byte_920AE6 = *((_BYTE *)v5 + 2);
  if ( v4 )
    result = sub_81BE34();
  return result;
}
