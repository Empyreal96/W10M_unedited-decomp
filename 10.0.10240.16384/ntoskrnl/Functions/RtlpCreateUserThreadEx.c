// RtlpCreateUserThreadEx 
 
int __fastcall RtlpCreateUserThreadEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, _DWORD *a10, _DWORD *a11)
{
  int result; // r0
  int v12; // [sp+20h] [bp-68h]
  int v13; // [sp+28h] [bp-60h] BYREF
  int v14; // [sp+2Ch] [bp-5Ch]
  int v15; // [sp+30h] [bp-58h]
  int v16; // [sp+34h] [bp-54h]
  int v17; // [sp+38h] [bp-50h]
  int v18; // [sp+3Ch] [bp-4Ch]
  int v19; // [sp+40h] [bp-48h]
  int v20; // [sp+44h] [bp-44h]
  int v21; // [sp+48h] [bp-40h]
  int v22; // [sp+4Ch] [bp-3Ch]
  int v23; // [sp+50h] [bp-38h]
  int *v24; // [sp+54h] [bp-34h]
  int v25; // [sp+58h] [bp-30h]

  v13 = 0;
  v14 = 0;
  if ( (a3 & 0xFFFFFFE8) != 0 )
    return -1073741811;
  v15 = 24;
  v16 = 0;
  v18 = 512;
  v19 = a2;
  v17 = 0;
  v20 = 0;
  v22 = 65539;
  v23 = 8;
  v25 = 0;
  v24 = &v13;
  v21 = 20;
  result = ZwCreateThreadEx();
  if ( result >= 0 )
  {
    if ( a10 )
    {
      *a10 = v12;
      if ( a11 )
      {
        *a11 = v13;
        a11[1] = v14;
      }
      result = 0;
    }
    else
    {
      result = sub_7F6C98();
    }
  }
  return result;
}
