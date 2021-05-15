// IopGetSetSpecificExtension 
 
int __fastcall IopGetSetSpecificExtension(int a1, int a2, int a3, int a4, int *a5, int *a6)
{
  int result; // r0
  int v11; // r4
  int v12; // r8
  _BYTE *v13; // r0
  int v14[8]; // [sp+0h] [bp-20h] BYREF

  v14[1] = a4;
  v14[0] = 0;
  if ( !a4 || (result = IopAllocateFileObjectExtension(a1, 0), result >= 0) )
  {
    v11 = IopGetFileObjectExtension(a1, a2, v14);
    v12 = v14[0];
    if ( !v11 && a4 )
    {
      if ( ViVerifierDriverAddedThunkListHead )
        return sub_52A018();
      v13 = (_BYTE *)ExAllocatePoolWithTag(512, a3, 538996553);
      v11 = (int)v13;
      if ( !v13 )
        return -1073741670;
      memset(v13, 0, a3);
      if ( IopSetTypeSpecificFoExtension(v12, a2, v11) < 0 )
      {
        ExFreePoolWithTag(v11, 0);
        v11 = IopGetFileObjectExtension(a1, a2, 0);
      }
    }
    if ( a5 )
      *a5 = v11;
    if ( a6 )
      *a6 = v12;
    result = 0;
  }
  return result;
}
