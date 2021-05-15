// PspServerSiloDelete 
 
int __fastcall PspServerSiloDelete(int result)
{
  _DWORD *v1; // r4
  int v2; // r5
  unsigned int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0

  v1 = *(_DWORD **)(result + 144);
  v2 = result;
  if ( v1 )
  {
    PspNotifySeverSiloDeletion(result);
    v3 = v1[8];
    if ( v3 )
    {
      ExFreePoolWithTag(v3);
      v1[8] = 0;
    }
    v4 = v1[5];
    if ( v4 )
    {
      ObfDereferenceObject(v4);
      v1[5] = 0;
    }
    v5 = v1[6];
    if ( v5 )
    {
      ObfDereferenceObject(v5);
      v1[6] = 0;
    }
    if ( v1[3] )
    {
      ZwClose();
      v1[3] = 0;
    }
    v6 = v1[7];
    if ( v6 )
    {
      ObfDereferenceObject(v6);
      v1[7] = 0;
    }
    v7 = v1[16];
    if ( v7 )
    {
      ObfDereferenceObject(v7);
      v1[16] = 0;
    }
    RtlFreeAnsiString(v1 + 1);
    result = ExFreePoolWithTag((unsigned int)v1);
    *(_DWORD *)(v2 + 144) = 0;
  }
  return result;
}
