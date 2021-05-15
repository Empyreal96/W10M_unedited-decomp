// EtwpSetProviderTraitsUm 
 
int __fastcall EtwpSetProviderTraitsUm(int a1, int a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r4
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r9
  unsigned int v12; // r1
  _BYTE *v13; // r2
  unsigned int v14; // r1
  unsigned __int16 *i; // r2
  int v16; // r0
  _DWORD *v17; // r0
  _DWORD v20[2]; // [sp+10h] [bp-40h] BYREF
  int v21; // [sp+18h] [bp-38h]
  int v22; // [sp+1Ch] [bp-34h]
  _DWORD _20[18]; // [sp+20h] [bp-30h] BYREF

  _20[14] = a1;
  _20[16] = a3;
  _20[17] = a4;
  _20[15] = a2;
  v22 = a1;
  v20[1] = a3;
  v6 = 0;
  v21 = 0;
  if ( *(_DWORD *)(a1 + 8) && *(_WORD *)(a1 + 16) )
  {
    v7 = ObReferenceObjectByHandle(*(_DWORD *)a1, 2048, EtwpRegistrationObjectType, 1, (int)v20, 0);
    v6 = v20[0];
    if ( v7 < 0 )
      goto LABEL_38;
    if ( (*(_BYTE *)(v20[0] + 50) & 8) != 0 )
    {
      v7 = -1073741811;
      goto LABEL_38;
    }
    if ( *(_DWORD *)(v20[0] + 56) )
    {
      v7 = -1073741823;
      goto LABEL_38;
    }
    v8 = *(unsigned __int16 *)(a1 + 16);
    if ( *(_WORD *)(a1 + 16) )
    {
      v9 = *(_DWORD *)(a1 + 8);
      if ( v8 + v9 > MmUserProbeAddress || v8 + v9 < v9 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v10 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(a1 + 16) + 16, 1417114693);
    v11 = v10;
    v21 = v10;
    if ( v10 )
    {
      memmove(v10 + 16, *(_DWORD *)(a1 + 8), *(unsigned __int16 *)(a1 + 16));
      v12 = *(unsigned __int16 *)(a1 + 16);
      if ( v12 >= 3 )
      {
        if ( *(unsigned __int16 *)(v11 + 16) == v12 )
        {
          v13 = (_BYTE *)(v11 + 18);
          v14 = v12 + v11 + 16;
          while ( *v13 )
          {
            if ( ++v13 == (_BYTE *)v14 )
            {
              v7 = -1073741566;
              goto LABEL_36;
            }
          }
          for ( i = (unsigned __int16 *)(v13 + 1); (unsigned int)i < v14; i = (unsigned __int16 *)((char *)i + *i) )
          {
            if ( (unsigned int)(i + 1) > v14 )
            {
              v7 = -1073741566;
              goto LABEL_36;
            }
          }
          if ( (unsigned int)i > v14 )
          {
            v7 = -1073741566;
          }
          else
          {
            v16 = EtwpSetProviderTraitsCommon(v6, v11, &EtwpProviderTraitsUmMutex, &EtwpProviderTraitsUmTree);
            v7 = v16;
            if ( v16 < 0 )
              goto LABEL_38;
            if ( !*(_DWORD *)(v6 + 20) )
            {
              v17 = (_DWORD *)EtwpGetProviderGroupFromTraits(*(_DWORD *)(v6 + 56) + 16);
              if ( v17 )
              {
                _20[0] = *v17;
                _20[1] = v17[1];
                _20[2] = v17[2];
                _20[3] = v17[3];
                v7 = EtwpAddRegEntryToGroup(v6, _20, a1, a2, a3);
              }
            }
          }
        }
        else
        {
          v7 = -1073741566;
        }
      }
      else
      {
        v7 = -1073741566;
      }
    }
    else
    {
      v7 = -1073741670;
    }
  }
  else
  {
    v7 = -1073741811;
  }
LABEL_36:
  if ( !v7 )
    *(_BYTE *)(v6 + 53) = 1;
LABEL_38:
  if ( v6 )
    ObfDereferenceObject(v6);
  return v7;
}
