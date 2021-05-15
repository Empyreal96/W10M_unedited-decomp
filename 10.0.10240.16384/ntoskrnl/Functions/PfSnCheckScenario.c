// PfSnCheckScenario 
 
int __fastcall PfSnCheckScenario(int a1, _DWORD *a2)
{
  int v2; // r0

  v2 = *((_DWORD *)&PfGlobals + a1 + 16);
  if ( !v2 )
    return -1073741399;
  if ( (dword_637410 & 1) != 0 && (dword_637270 & 1) == 0 )
    return -1073741725;
  if ( dword_6373A8 == 1 )
    return -1073741296;
  if ( !dword_637348 )
    return -1073741127;
  *a2 = v2;
  return 0;
}
