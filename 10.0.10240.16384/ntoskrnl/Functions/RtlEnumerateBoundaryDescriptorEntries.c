// RtlEnumerateBoundaryDescriptorEntries 
 
int __fastcall RtlEnumerateBoundaryDescriptorEntries(_DWORD *a1, int (__fastcall *a2)(_DWORD *, int), int a3)
{
  unsigned int v4; // r0
  int v5; // lr
  unsigned int v6; // r6
  _DWORD *v7; // r5
  int v8; // r7
  int v9; // r8
  unsigned int v10; // r2
  char *v11; // r9

  v4 = a1[2];
  v5 = a3;
  if ( v4 >= 0x10 && *a1 == 1 )
  {
    v6 = (unsigned int)a1 + v4;
    if ( (_DWORD *)((char *)a1 + v4) >= a1 )
    {
      v7 = a1 + 4;
      v8 = 0;
      v9 = 0;
      if ( (unsigned int)(a1 + 6) >= v6 )
      {
LABEL_13:
        if ( a1[1] == v8 )
          return 0;
      }
      else
      {
        while ( 1 )
        {
          v10 = v7[1];
          ++v8;
          if ( v10 < 8 )
            break;
          v11 = (char *)v7 + v10;
          if ( (_DWORD *)((char *)v7 + v10) < v7 || (unsigned int)v11 > v6 )
            break;
          if ( *v7 == 1 )
          {
            if ( (unsigned int)++v9 > 1 )
              return -1073741635;
          }
          else
          {
            if ( *v7 != 2 )
              return sub_7EF774();
            if ( !RtlpValidateSidBuffer() )
              return -1073741811;
            v5 = a3;
          }
          if ( a2 && !a2(v7, v5) )
            goto LABEL_13;
          v7 = (_DWORD *)((unsigned int)(v11 + 7) & 0xFFFFFFF8);
          if ( (unsigned int)(v7 + 2) >= v6 )
            goto LABEL_13;
          v5 = a3;
        }
      }
    }
  }
  return -1073741811;
}
