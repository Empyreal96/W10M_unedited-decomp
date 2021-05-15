// AlpcpCaptureSecurityAttributeInternal 
 
int __fastcall AlpcpCaptureSecurityAttributeInternal(_DWORD *a1, int a2, int a3, int *a4, int a5)
{
  int v8; // r1
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int result; // r0
  int v13; // r4
  int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r1
  int v21[6]; // [sp+8h] [bp-18h] BYREF

  v21[0] = a3;
  v21[1] = (int)a4;
  if ( (a2 & 0xFFFCFFFF) != 0 || (a2 & 0x30000) == 196608 )
    return -1073741811;
  v8 = *a4;
  if ( *a4 != -2 )
  {
    v9 = a1[2];
    if ( v9 )
    {
      v10 = AlpcReferenceBlobByHandle((_DWORD *)(v9 + 20), v8, AlpcSecurityType);
      v11 = v10;
      if ( v10 )
      {
        if ( a1 != *(_DWORD **)(v10 + 12) )
          return sub_7F7F44();
        if ( (a2 & 0x10000) != 0 )
        {
          if ( AlpcpDeleteBlob(v10) )
          {
            __dmb(0xBu);
            v15 = (unsigned int *)(v11 - 12);
            do
            {
              v16 = __ldrex(v15);
              v17 = v16 - 1;
            }
            while ( __strex(v17, v15) );
            __dmb(0xBu);
            if ( v17 <= 0 )
            {
              if ( v17 )
                KeBugCheckEx(24, 0, v11, 33, v17);
              AlpcpDestroyBlob(v11);
            }
          }
          __dmb(0xBu);
          v18 = (unsigned int *)(v11 - 12);
          do
          {
            v19 = __ldrex(v18);
            v20 = v19 - 1;
          }
          while ( __strex(v20, v18) );
          __dmb(0xBu);
          if ( v20 <= 0 )
          {
            if ( v20 )
              KeBugCheckEx(24, 0, v11, 33, v20);
            AlpcpDestroyBlob(v11);
          }
          v11 = 0;
        }
        result = 0;
        *(_DWORD *)(a5 + 16) = v11;
        return result;
      }
    }
    return -1073741816;
  }
  if ( (a2 & 0x20000) != 0 )
  {
    v13 = 1;
  }
  else
  {
    if ( (a2 & 0x10000) != 0 )
      return -1073741816;
    v13 = 0;
  }
  result = AlpcpCreateSecurityContext(a1, v13, a3, v21);
  if ( result >= 0 )
  {
    v14 = v21[0];
    *(_DWORD *)(a5 + 16) = v21[0];
    if ( v13 )
      *a4 = *(_DWORD *)(v14 + 4);
  }
  return result;
}
