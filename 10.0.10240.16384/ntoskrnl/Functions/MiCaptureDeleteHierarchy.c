// MiCaptureDeleteHierarchy 
 
unsigned int __fastcall MiCaptureDeleteHierarchy(unsigned int result, unsigned int a2, int a3, _DWORD *a4)
{
  unsigned int i; // r5
  int v5; // r4
  int *v6; // r6
  _DWORD *v7; // t1
  unsigned int v8; // [sp+Ch] [bp-24h] BYREF
  _DWORD *v9; // [sp+10h] [bp-20h]

  v9 = a4;
  *a4 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v5 = 0;
    v8 = ((result >> 20) & 0xFFC) - 1070596096;
    v6 = (int *)&v8;
    while ( 1 )
    {
      v7 = (_DWORD *)*v6++;
      if ( !*v7 )
        break;
      if ( ++v5 )
        goto LABEL_5;
    }
    *((_BYTE *)v9 + i) = 1 << -(char)v5;
LABEL_5:
    result = a2;
  }
  return result;
}
