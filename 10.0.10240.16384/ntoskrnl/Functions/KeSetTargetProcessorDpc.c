// KeSetTargetProcessorDpc 
 
int __fastcall KeSetTargetProcessorDpc(int result, char a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v5; // r7
  unsigned __int16 v6; // r3
  unsigned __int16 v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r2
  int v10; // r1
  int v11; // r3
  _DWORD v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v4 = a2;
  v5 = result;
  if ( KeForceGroupAwareness )
    v6 = KiActiveGroups - 1;
  else
    v6 = 0;
  v7 = v6;
  if ( v6 == 0xFFFF )
  {
    v8 = KeNumberProcessors_0;
  }
  else if ( v6 >= (unsigned int)(unsigned __int16)KiActiveGroups )
  {
    v8 = 0;
  }
  else
  {
    v9 = ~dword_681D78[v6];
    v10 = *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)v9);
    v9 >>= 8;
    v11 = *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)v9);
    result = v11 + v10;
    v8 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE1(v9))
                         + *((_BYTE *)RtlpBitsClearTotal + HIWORD(v9))
                         + v11
                         + v10);
  }
  if ( v4 < v8 )
  {
    LOWORD(v12[0]) = v7;
    HIWORD(v12[0]) = (unsigned __int8)v4;
    result = KeSetTargetProcessorDpcEx(v5, (int)v12);
  }
  return result;
}
