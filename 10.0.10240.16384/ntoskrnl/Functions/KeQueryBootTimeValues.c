// KeQueryBootTimeValues 
 
int __fastcall KeQueryBootTimeValues(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r0
  int v7; // r3
  int v8; // r3

  v6 = KfRaiseIrql(2);
  v7 = MEMORY[0xFFFF9018];
  __dmb(0xBu);
  a1[1] = v7;
  v8 = MEMORY[0xFFFF9014];
  __dmb(0xBu);
  *a1 = v8;
  if ( a1[1] != MEMORY[0xFFFF901C] )
    return sub_50B518(v6);
  *a2 = KeBootTime;
  a2[1] = MEMORY[0x681E0C];
  *a3 = KeBootTimeBias;
  a3[1] = MEMORY[0x68202C];
  return KfLowerIrql(v6);
}
