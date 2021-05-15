// IoGetRelatedDeviceObject 
 
int __fastcall IoGetRelatedDeviceObject(_DWORD *a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r2
  int *v5; // r1
  int v6; // r3
  int *v7; // r3
  int v8; // r3

  v2 = a1[2];
  if ( (!v2 || (result = *(_DWORD *)(v2 + 8)) == 0)
    && ((a1[11] & 0x800) != 0 || (v6 = *(_DWORD *)(a1[1] + 36)) == 0 || (result = *(_DWORD *)(v6 + 8)) == 0) )
  {
    result = a1[1];
  }
  v4 = *(_DWORD *)(result + 16);
  if ( v4 )
  {
    v5 = (int *)a1[31];
    if ( v5 && v5 != IopRevocationExtension && (v7 = (int *)v5[2]) != 0 && (v8 = *v7) != 0 )
    {
      while ( result != v8 )
      {
        result = *(_DWORD *)(result + 16);
        if ( !result )
          goto LABEL_5;
      }
      result = v8;
    }
    else
    {
      do
      {
LABEL_5:
        result = v4;
        v4 = *(_DWORD *)(v4 + 16);
      }
      while ( v4 );
    }
  }
  return result;
}
