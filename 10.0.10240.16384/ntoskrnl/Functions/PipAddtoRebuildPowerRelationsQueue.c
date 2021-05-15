// PipAddtoRebuildPowerRelationsQueue 
 
int __fastcall PipAddtoRebuildPowerRelationsQueue(int a1)
{
  int result; // r0
  int v2; // r1
  _DWORD *v3; // r4
  int *v4; // r5
  int **v5; // r1

  result = PipIsDeviceReadyForPowerRelations(a1, a1);
  if ( result )
  {
    v3 = (_DWORD *)(v2 ? *(_DWORD *)(*(_DWORD *)(v2 + 176) + 44) : 0);
    if ( v3 )
    {
      result = v3[6];
      if ( result )
      {
        v4 = v3 + 9;
        if ( (_DWORD *)v3[9] == v3 + 9 )
        {
          result = ObfReferenceObject(result);
          ++v3[11];
          v5 = (int **)dword_630D94;
          *v4 = (int)&PiRebuildPowerRelationsQueue;
          v3[10] = v5;
          if ( *v5 != &PiRebuildPowerRelationsQueue )
            sub_7C9CA8(result);
          *v5 = v4;
          dword_630D94 = (int)(v3 + 9);
        }
      }
    }
  }
  return result;
}
