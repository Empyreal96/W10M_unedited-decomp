// PnpBuildCmResourceLists 
 
int __fastcall PnpBuildCmResourceLists(int result, unsigned int a2, int a3)
{
  unsigned int v4; // r10
  unsigned int v5; // r8
  unsigned int v6; // r2
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r6
  int v10; // r7
  int v11; // r0
  unsigned int v12; // [sp+0h] [bp-30h]
  int v13; // [sp+4h] [bp-2Ch]

  v4 = result;
  v13 = result;
  if ( a3 )
    return sub_80D9A0();
  v5 = -1;
  do
  {
    v6 = v5;
    v12 = v5;
    v5 = 0;
    v7 = v4;
    if ( v4 >= a2 )
      break;
    do
    {
      v8 = *(_DWORD *)(v7 + 4);
      *(_DWORD *)(v7 + 28) = 0;
      if ( (v8 & 0x28) == 0 )
      {
        if ( (v8 & 0x10) != 0 )
        {
          *(_DWORD *)(v7 + 36) = -1073741823;
        }
        else if ( v6 == -1 || *(_DWORD *)(v7 + 36) == -1073741267 )
        {
          *(_DWORD *)(v7 + 36) = 0;
          result = PnpBuildCmResourceList(v7, 1);
          if ( *(_DWORD *)(v7 + 36) == -1073741267 )
          {
            ++v5;
          }
          else
          {
            v9 = *(_DWORD *)(v7 + 28);
            if ( v9 )
            {
              if ( *(_DWORD *)v7 )
                v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v7 + 176) + 20);
              else
                v10 = 0;
              v11 = PnpDetermineResourceListSize(*(int **)(v7 + 28));
              result = IopWriteAllocatedResourcesToRegistry(v10, v9, v11);
            }
          }
          v6 = v12;
        }
      }
      v7 += 40;
    }
    while ( v7 < a2 );
    v4 = v13;
    if ( !v5 )
      break;
  }
  while ( v5 < v6 );
  return result;
}
