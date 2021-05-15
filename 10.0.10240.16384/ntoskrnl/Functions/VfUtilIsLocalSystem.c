// VfUtilIsLocalSystem 
 
int __fastcall VfUtilIsLocalSystem(_DWORD *a1)
{
  int v2; // r4
  int *v3; // r0
  char v5[4]; // [sp+18h] [bp-20h] BYREF
  char v6[4]; // [sp+1Ch] [bp-1Ch] BYREF
  int v7[6]; // [sp+20h] [bp-18h] BYREF

  if ( !ViInitializeLocalSystemDescriptor() )
    return 1;
  SeCaptureSubjectContextEx(0, a1, v7);
  v3 = IoGetFileObjectGenericMapping();
  v2 = SeAccessCheck(ViLocalSystemDescriptor, (int)v7, 0, 1, 0, 0, (int)v3, 1, (int)v6, (int)v5);
  SeReleaseSubjectContext((int)v7);
  return v2;
}
