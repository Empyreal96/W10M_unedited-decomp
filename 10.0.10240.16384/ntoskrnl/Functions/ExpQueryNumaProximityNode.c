// ExpQueryNumaProximityNode 
 
int __fastcall ExpQueryNumaProximityNode(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  int result; // r0
  int v7; // r4
  __int16 v8; // r2
  unsigned int v9; // r1
  _DWORD *v10; // [sp+0h] [bp-18h] BYREF
  int v11; // [sp+4h] [bp-14h]
  int varg_r0; // [sp+20h] [bp+8h]
  unsigned int varg_r1; // [sp+24h] [bp+Ch]
  _DWORD *varg_r2; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v10 = a3;
  v11 = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  if ( a2 < 8 )
  {
    result = -1073741820;
    goto LABEL_14;
  }
  v7 = *(_DWORD *)a1;
  v11 = *(_DWORD *)a1;
  result = 0;
  v8 = 0;
  LOWORD(v10) = 0;
  if ( PnpQueryProximityNode )
  {
    result = PnpQueryProximityNode(v7, &v10);
    v8 = (__int16)v10;
    if ( result < 0 )
      goto LABEL_14;
    v9 = 0;
    if ( KeNumberNodes )
    {
      while ( *((unsigned __int16 *)*(&KeNodeBlock + v9) + 133) != (unsigned __int16)v10 )
      {
        v9 = (unsigned __int16)(v9 + 1);
        if ( v9 >= (unsigned __int16)KeNumberNodes )
          goto LABEL_10;
      }
      v8 = v9;
      LOWORD(v10) = v9;
    }
LABEL_10:
    if ( v9 >= (unsigned __int16)KeNumberNodes )
      result = -1073741595;
  }
  if ( result >= 0 )
    *(_WORD *)(a1 + 4) = v8;
LABEL_14:
  if ( a3 )
    *a3 = 8;
  return result;
}
