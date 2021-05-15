// MiInitializePageAccessLogging 
 
int *__fastcall MiInitializePageAccessLogging(int a1, _DWORD *a2, int a3, int a4)
{
  int *result; // r0
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v7 = a3;
  v8 = a4;
  a2[8] = a2 + 14;
  a2[1] = 0;
  *(_DWORD *)((char *)a2 + a3 - 4) = 0;
  *a2 = 0;
  a2[10] = (char *)a2 + a3 - 4;
  a2[9] = (char *)a2 + a3 - 8;
  a2[12] = 0;
  if ( (*(_BYTE *)(a1 + 112) & 7u) < 2 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
    {
      a2[11] = 1;
      a2[12] = *(_DWORD *)(a1 - 3240);
    }
    else
    {
      a2[11] = a1 - 492;
    }
  }
  else
  {
    a2[11] = 0;
  }
  result = KeQueryTickCount(&v6);
  a2[4] = v6;
  a2[5] = v7;
  return result;
}
