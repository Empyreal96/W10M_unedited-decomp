// ExGetAttachedSessionPoolTagInfo 
 
int __fastcall ExGetAttachedSessionPoolTagInfo(_DWORD *a1, unsigned int a2, _DWORD *a3, int a4)
{
  int v6; // r4
  int result; // r0
  int v9; // r3
  int v10; // [sp+0h] [bp-20h] BYREF
  int v11[7]; // [sp+4h] [bp-1Ch] BYREF

  v10 = a2;
  v11[0] = (int)a3;
  v11[1] = a4;
  v6 = 0;
  *a3 = 0;
  if ( a2 < 0x28 )
    return sub_7D5D18();
  result = ExGetSessionPoolTagInfo(a1 + 3, a2 - 12, (int)&v10, (int)v11);
  if ( result >= 0 )
  {
    v9 = v10;
    a1[1] = a4;
    a1[2] = v9;
    *a1 = 28 * (v9 - 1) + 40;
LABEL_5:
    result = v6;
    *a3 = 28 * (v11[0] - 1) + 40;
    return result;
  }
  if ( result == -1073741820 )
  {
    v6 = -1073741820;
    goto LABEL_5;
  }
  return result;
}
