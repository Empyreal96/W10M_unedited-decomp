// KiIntSteerChooseInitialTargetProcessors 
 
int __fastcall KiIntSteerChooseInitialTargetProcessors(int a1, int a2, int a3, unsigned int *a4, _DWORD *a5)
{
  int result; // r0
  int v7; // r5
  unsigned int v8; // r3
  char v9; // r3

  *a4 = 0;
  a4[1] = 0;
  a4[2] = 0;
  *a5 = 0;
  if ( KiInterruptSteeringDisabled )
    return sub_5535FC();
  v7 = *(unsigned __int16 *)(a3 + 24);
  if ( *(_WORD *)(a3 + 24) || *(_DWORD *)(a3 + 20) != dword_681D78[0] )
    return sub_5535FC();
  result = 1;
  if ( ((KiInterruptControllerInfo & 1) == 0 || *(_DWORD *)(a3 + 16))
    && ((KiInterruptControllerInfo & 2) == 0 || *(_DWORD *)(a3 + 16) != 1) )
  {
    return sub_5535FC();
  }
  *((_WORD *)a4 + 2) = v7;
  *a5 = 1;
  v8 = *(_DWORD *)&KiIntSteerMask[2 * v7 + 4];
  *a4 = v8;
  if ( v8 )
    v9 = __clz(__rbit(v8));
  else
    v9 = -1;
  *a4 = 0;
  a4[1] = 0;
  a4[2] = 0;
  *a4 = 1 << v9;
  return result;
}
