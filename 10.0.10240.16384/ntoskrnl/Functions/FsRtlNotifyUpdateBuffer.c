// FsRtlNotifyUpdateBuffer 
 
int __fastcall FsRtlNotifyUpdateBuffer(_DWORD *a1, int a2, unsigned __int16 *a3, unsigned __int16 *a4, unsigned __int16 *a5, char a6, int a7)
{
  int v10; // r6
  int result; // r0
  unsigned int v12; // r2
  int v13; // r1
  char *v14; // r3
  unsigned int v15; // r2
  int v16; // r1
  int v17; // r0
  int v18; // r2
  char *v19; // r0
  _DWORD v20[7]; // [sp+Ch] [bp-1Ch] BYREF

  v20[0] = a3;
  v20[1] = a4;
  v10 = 0;
  *a1 = 0;
  a1[1] = a2;
  if ( a7 == 12 )
  {
    result = 0;
    LOBYTE(v20[0]) = 0;
    return result;
  }
  a1[2] = a7 - 12;
  if ( !a6 )
  {
    if ( *a3 )
    {
      RtlOemToUnicodeN(a1 + 3, a1[2], v20, *((_DWORD *)a3 + 1), *a3);
      v18 = v20[0];
      *(_WORD *)((char *)a1 + v20[0] + 12) = 92;
      v10 = v18 + 2;
    }
    if ( *a3 )
    {
      RtlOemToUnicodeN((char *)a1 + v10 + 12, a1[2], v20, *((_DWORD *)a4 + 1), *a4);
      if ( a5 )
      {
        v19 = (char *)a1 + v20[0] + v10;
        *((_WORD *)v19 + 6) = 58;
        RtlOemToUnicodeN(v19 + 14, a1[2], v20, *((_DWORD *)a5 + 1), *a5);
      }
      return 1;
    }
    v15 = *a5;
    v16 = *((_DWORD *)a5 + 1);
    v17 = (int)a1 + v10 + 12;
    goto LABEL_14;
  }
  v12 = *a3;
  if ( *a3 )
  {
    memmove((int)(a1 + 3), *((_DWORD *)a3 + 1), v12);
    v13 = *a3;
    if ( a1[2] < (unsigned int)(v13 + 2) )
    {
      result = 0;
      LOBYTE(v20[0]) = 0;
      return result;
    }
    *(_WORD *)((char *)a1 + v13 + 12) = 92;
    v10 = *a3 + 2;
  }
  memmove((int)a1 + v10 + 12, *((_DWORD *)a4 + 1), *a4);
  if ( a5 )
  {
    v14 = (char *)a1 + *a4 + v10;
    *((_WORD *)v14 + 6) = 58;
    v15 = *a5;
    v16 = *((_DWORD *)a5 + 1);
    v17 = (int)(v14 + 14);
LABEL_14:
    memmove(v17, v16, v15);
  }
  return 1;
}
