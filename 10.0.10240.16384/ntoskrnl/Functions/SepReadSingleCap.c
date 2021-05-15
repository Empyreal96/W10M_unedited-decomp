// SepReadSingleCap 
 
int __fastcall SepReadSingleCap(int a1, int a2, unsigned int a3, int a4, int *a5)
{
  int v5; // r5
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r8
  unsigned int v9; // r6
  int v10; // r4
  int v11; // r0
  int v12; // r6
  int v13; // r1
  unsigned int v14; // r4
  unsigned int v15; // r1
  int v16; // r2
  unsigned int v17; // r3
  unsigned int v19; // [sp+Ch] [bp-2Ch]
  int v20; // [sp+10h] [bp-28h]

  v5 = ExAllocatePoolWithTag(1, a2 + 18, 1884513619);
  if ( v5 )
  {
    v6 = ZwQueryValueKey();
    if ( v6 < 0 )
      goto LABEL_27;
    v7 = *(_DWORD *)(v5 + 8);
    v8 = v7 ? v7 >> 2 : 0;
    v6 = ZwQueryValueKey();
    if ( v6 < 0 )
      goto LABEL_27;
    v9 = ((4 * v8 + 41) & 0xFFFFFFFE) + *(_DWORD *)(v5 + 8);
    v6 = ZwQueryValueKey();
    if ( v6 < 0 )
      goto LABEL_27;
    v10 = *(_DWORD *)(v5 + 8) + v9;
    v11 = ExAllocatePoolWithTag(1, v10, 1884513619);
    v12 = v11;
    if ( v11 )
    {
      v19 = v11 + v10;
      v6 = ZwQueryValueKey();
      if ( v6 >= 0 )
      {
        if ( *(_DWORD *)(v5 + 8) == 4 )
        {
          *(_DWORD *)(v12 + 28) = *(_DWORD *)(v5 + 12);
          v6 = ZwQueryValueKey();
          if ( v6 >= 0 )
          {
            v13 = *(_DWORD *)(v5 + 8);
            v14 = (v12 + 4 * v8 + 41) & 0xFFFFFFFE;
            if ( v13 + v14 <= v19 )
            {
              *(_WORD *)(v12 + 22) = v13;
              *(_WORD *)(v12 + 20) = v13;
              *(_DWORD *)(v12 + 24) = v14;
              memmove((v12 + 4 * v8 + 41) & 0xFFFFFFFE, v5 + 12, *(_DWORD *)(v5 + 8));
              v20 = *(_DWORD *)(v5 + 8) + v14;
              v6 = ZwQueryValueKey();
              if ( v6 < 0 )
                goto LABEL_27;
              if ( *(_DWORD *)(v5 + 8) + v20 <= v19 )
              {
                *(_DWORD *)(v12 + 12) = v20;
                memmove(v20, v5 + 12, *(_DWORD *)(v5 + 8));
                v6 = ZwQueryValueKey();
                if ( v6 < 0 )
                  goto LABEL_27;
                v15 = 0;
                *(_DWORD *)(v12 + 32) = v8;
                if ( !v8 )
                {
LABEL_24:
                  if ( RtlValidSid(*(_BYTE **)(v12 + 12)) )
                    *a5 = v12;
                  else
                    v6 = -1073741704;
                  goto LABEL_27;
                }
                v16 = v12;
                while ( 1 )
                {
                  v17 = *(_DWORD *)(v5 - v12 + v16 + 12);
                  if ( v17 >= a3 )
                    break;
                  *(_DWORD *)(v16 + 36) = a4 + 28 * v17;
                  ++v15;
                  v16 += 4;
                  if ( v15 >= v8 )
                    goto LABEL_24;
                }
              }
            }
            v6 = -1073741789;
          }
        }
        else
        {
          v6 = -1073741811;
        }
      }
    }
    else
    {
      v6 = -1073741670;
    }
LABEL_27:
    ExFreePoolWithTag(v5);
    return v6;
  }
  return -1073741670;
}
