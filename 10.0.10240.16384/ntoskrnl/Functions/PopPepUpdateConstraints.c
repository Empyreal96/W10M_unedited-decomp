// PopPepUpdateConstraints 
 
int __fastcall PopPepUpdateConstraints(int a1, int a2, int a3)
{
  int v5; // r9
  unsigned int v6; // r6
  unsigned int v7; // r10
  int v8; // r4
  int result; // r0
  unsigned int v10; // r0
  unsigned int v11; // r6
  int v12; // r4
  char v13[4]; // [sp+8h] [bp-28h] BYREF
  int v14; // [sp+Ch] [bp-24h]

  v5 = PopPepLockActivityLink(a1, 0, 4, 1u, v13);
  v14 = v5;
  v6 = 0;
  v7 = PopPepCountReadyActivities(a1, 0, 3);
  if ( *(_DWORD *)(a1 + 120) )
  {
    v8 = a1 + 128;
    do
    {
      if ( (*(_DWORD *)(v8 + 16) & 1) != 0 )
        return sub_54B4B0();
      ++v6;
      v8 += 168;
    }
    while ( v6 < *(_DWORD *)(a1 + 120) );
    v5 = v14;
  }
  PopPepPromoteActivities(a1, 0, 3);
  v10 = PopPepCountReadyActivities(a1, 0, 3);
  PopPepRequestWork(v7, v10);
  result = PopPepReleaseActivityLink(a1, 0, v5, (unsigned __int8)v13[0]);
  if ( !a3 )
  {
    v11 = 0;
    if ( *(_DWORD *)(a1 + 120) )
    {
      v12 = a1 + 128;
      do
      {
        if ( (*(_DWORD *)(v12 + 16) & 1) != 0 )
          result = KeWaitForSingleObject(v12 + 32, 0, 0, 0, 0);
        ++v11;
        v12 += 168;
      }
      while ( v11 < *(_DWORD *)(a1 + 120) );
    }
  }
  return result;
}
