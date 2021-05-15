// KiSetIdealNodeProcessByGroup 
 
int __fastcall KiSetIdealNodeProcessByGroup(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r8
  _WORD *v6; // r4
  int result; // r0
  int v10; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+4h] [bp-1Ch]
  int v12; // [sp+8h] [bp-18h]

  v10 = a2;
  v11 = a3;
  v12 = a4;
  v4 = a1 + 4 * a3;
  v5 = *(_DWORD *)(v4 + 72);
  v6 = (_WORD *)a2;
  v10 = v5;
  v12 = 0;
  v11 = (unsigned __int16)a3;
  if ( !a2 )
    v6 = KeSelectNodeForAffinity();
  *(_WORD *)(a1 + 2 * a3 + 112) = v6[133];
  v10 = *((_DWORD *)v6 + 65) & v5;
  result = KeSelectIdealProcessor(v6, &v10, 0);
  *(_DWORD *)(v4 + 108) = result;
  return result;
}
