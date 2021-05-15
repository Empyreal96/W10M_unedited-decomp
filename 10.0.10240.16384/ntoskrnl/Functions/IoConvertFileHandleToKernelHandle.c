// IoConvertFileHandleToKernelHandle 
 
int __fastcall IoConvertFileHandleToKernelHandle(int a1, char a2, int a3, int a4, int *a5)
{
  int v8; // r4
  int v9; // r7
  int v10; // r0
  int v11; // r5
  int v13; // r6
  int v14[2]; // [sp+10h] [bp-30h] BYREF
  int v15[10]; // [sp+18h] [bp-28h] BYREF

  *a5 = 0;
  if ( !a1 )
    return 0;
  v8 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, a2, v14);
  if ( v8 >= 0 )
  {
    v9 = v14[0];
    if ( a4 || (v15[1] & a3) == a3 )
    {
      v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v8 = ObDuplicateObject(v10, a1, PsInitialSystemProcess, v14, a3, 512, 0, 0);
      if ( v8 >= 0 )
      {
        v11 = v14[0];
        v8 = ObReferenceObjectByHandle(v14[0], 0, IoFileObjectType, 0, v15);
        if ( v8 < 0 )
          return sub_7E9510();
        v13 = v15[0];
        if ( v15[0] == v9 )
        {
          *a5 = v11;
        }
        else
        {
          v8 = -1073741788;
          ObCloseHandle(v11);
        }
        ObfDereferenceObject(v13);
      }
    }
    else
    {
      v8 = -1073741790;
    }
    ObfDereferenceObject(v9);
  }
  return v8;
}
