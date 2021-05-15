// PiDevCfgQueryPolicyStringList 
 
int __fastcall PiDevCfgQueryPolicyStringList(int a1, unsigned __int16 *a2, int *a3)
{
  int v5; // r5
  int v6; // r6
  int v7; // r4
  _DWORD *v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r7
  int v12; // r9
  int v13; // r8
  unsigned int v14; // r10
  unsigned int v15; // r3
  int v18; // r0
  unsigned int v19; // r7
  _DWORD *v21; // [sp+8h] [bp-80h] BYREF
  int v22; // [sp+Ch] [bp-7Ch]
  _DWORD *v23; // [sp+10h] [bp-78h] BYREF
  int v24; // [sp+14h] [bp-74h]
  char v25[2]; // [sp+18h] [bp-70h] BYREF
  unsigned __int16 v26; // [sp+1Ah] [bp-6Eh]
  int v27; // [sp+1Ch] [bp-6Ch]
  int *v28; // [sp+20h] [bp-68h]
  int v29; // [sp+28h] [bp-60h]
  int v30; // [sp+2Ch] [bp-5Ch]
  char *v31; // [sp+30h] [bp-58h]
  int v32; // [sp+34h] [bp-54h]
  int v33; // [sp+38h] [bp-50h]
  int v34; // [sp+3Ch] [bp-4Ch]
  char v35[20]; // [sp+40h] [bp-48h] BYREF
  int v36; // [sp+54h] [bp-34h]
  int v37; // [sp+58h] [bp-30h]
  int v38; // [sp+5Ch] [bp-2Ch]

  v21 = 0;
  v22 = 0;
  v28 = a3;
  v5 = 0;
  v6 = 0;
  v7 = IopGetRegistryValue(a1, a2, 0, (int *)&v21);
  if ( v7 < 0 )
  {
    v9 = v21;
LABEL_48:
    if ( v9 )
      ExFreePoolWithTag((unsigned int)v9);
    goto LABEL_50;
  }
  if ( v21[1] == 4 && v21[3] == 4 )
    v5 = *(_DWORD *)((char *)v21 + v21[2]);
  ExFreePoolWithTag((unsigned int)v21);
  if ( v5 != 1 )
    goto LABEL_9;
  RtlInitUnicodeString((unsigned int)v25, a2);
  v22 = 0;
  v29 = 24;
  v30 = a1;
  v32 = 576;
  v31 = v25;
  v33 = 0;
  v34 = 0;
  v7 = ZwOpenKey();
  if ( v7 >= 0 )
  {
    v7 = NtQueryKey(v22, 4, v35, 0x28u, &v23);
    if ( v7 >= 0 )
    {
      if ( !v36 )
      {
LABEL_9:
        v7 = -1073741275;
        goto LABEL_50;
      }
      v21 = (_DWORD *)(v38 + 2 * (v37 + 12));
      v9 = (_DWORD *)ExAllocatePoolWithTag(1, (int)v21, 1667526736);
      if ( !v9 )
      {
        v7 = -1073741670;
        goto LABEL_50;
      }
      v10 = v38 * v36 + 2;
      v24 = -2147483622;
      while ( 2 )
      {
        if ( v6 )
          ExFreePoolWithTag(v6);
        v6 = ExAllocatePoolWithTag(1, v10, 1667526736);
        if ( v6 )
        {
          v11 = 0;
          v12 = 0;
          v13 = 0;
          v14 = v10 >> 1;
          while ( 1 )
          {
            v18 = ZwEnumerateValueKey();
            v7 = v18;
            if ( v18 == v24 )
              break;
            if ( v18 == -2147483643 )
            {
              ExFreePoolWithTag((unsigned int)v9);
              v21 = v23;
              v9 = (_DWORD *)ExAllocatePoolWithTag(1, (int)v23, 1667526736);
              if ( !v9 )
              {
                v7 = -1073741670;
                goto LABEL_44;
              }
              --v13;
            }
            else
            {
              if ( v18 < 0 )
                goto LABEL_44;
              if ( v9[1] == 1 )
              {
                v15 = v9[3];
                if ( v15 >= 2 && !*(_WORD *)((char *)v9 + 2 * (v15 >> 1) + v9[2] - 2) )
                {
                  v7 = RtlInitUnicodeStringEx((int)v25, (unsigned __int16 *)((char *)v9 + v9[2]));
                  if ( v7 < 0 )
                    goto LABEL_44;
                  v11 += v26 >> 1;
                  if ( v14 > v11 )
                  {
                    RtlStringCchCopyExW((_WORD *)(v6 + 2 * v12), v14 - v12, v27);
                    v12 += v26 >> 1;
                  }
                }
              }
            }
            ++v13;
          }
          v7 = 0;
          if ( v11 )
          {
            v19 = v11 + 1;
            if ( v14 < v19 )
            {
              v10 = 2 * v19;
              continue;
            }
            *(_WORD *)(v6 + 2 * v12) = 0;
            *v28 = v6;
            v6 = 0;
          }
          else
          {
            v7 = -1073741275;
          }
LABEL_44:
          if ( v6 )
            ExFreePoolWithTag(v6);
        }
        else
        {
          v7 = -1073741670;
        }
        goto LABEL_48;
      }
    }
  }
LABEL_50:
  if ( v22 )
    ZwClose();
  return v7;
}
