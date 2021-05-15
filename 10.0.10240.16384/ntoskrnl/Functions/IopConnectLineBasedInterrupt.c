// IopConnectLineBasedInterrupt 
 
int __fastcall IopConnectLineBasedInterrupt(int a1, unsigned int *a2, int a3, int a4, int a5, unsigned __int8 a6)
{
  unsigned int v6; // r7
  int v7; // r3
  int v8; // r4
  unsigned int *v9; // r6
  unsigned int v10; // r1
  unsigned int v11; // r8
  unsigned int v12; // r9
  _DWORD *v14; // r2
  _BYTE *v15; // r0
  unsigned int v16; // r5
  unsigned int v17; // r3
  unsigned int *v18; // r2
  unsigned int *v19; // r10
  _DWORD *v20; // r1
  int v21; // t1
  unsigned int v22; // r3
  unsigned int v23; // r6
  int v24; // [sp+10h] [bp-140h]
  unsigned int *v25; // [sp+18h] [bp-138h] BYREF
  _DWORD *v26; // [sp+1Ch] [bp-134h]
  unsigned int *v27; // [sp+20h] [bp-130h]
  int v28; // [sp+24h] [bp-12Ch]
  int v29; // [sp+28h] [bp-128h]
  char v30[176]; // [sp+30h] [bp-120h] BYREF
  int v31[28]; // [sp+E0h] [bp-70h] BYREF

  v28 = a3;
  v29 = a4;
  v6 = 0;
  v25 = 0;
  *a2 = 0;
  v27 = a2;
  if ( !a1 )
    return -1073741811;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v7 || (*(_DWORD *)(v7 + 268) & 0x20000) != 0 || !a3 )
    return -1073741811;
  v8 = IopGetInterruptConnectionData(a1, &v25);
  if ( v8 >= 0 )
  {
    v9 = v25;
    if ( v25 )
    {
      v10 = *v25;
      v11 = 0;
      v12 = 0;
      if ( *v25 )
      {
        v14 = v25 + 2;
        do
        {
          if ( !*v14 )
          {
            ++v11;
            if ( v12 < *((unsigned __int8 *)v14 + 8) )
              v12 = *((unsigned __int8 *)v14 + 8);
          }
          v14 += 18;
          --v10;
        }
        while ( v10 );
        if ( v11 )
        {
          if ( !a6 )
          {
LABEL_18:
            v15 = (_BYTE *)ExAllocatePoolWithTag(512, 4 * (v11 + 47), 1852403529);
            v16 = (unsigned int)v15;
            if ( v15 )
            {
              memset(v15, 0, 4 * (v11 + 47));
              *(_BYTE *)(v16 + 176) = v12;
              *(_DWORD *)(v16 + 180) = v11;
              memset(v31, 0, 80);
              v31[0] = 1;
              v17 = *v9;
              v18 = 0;
              v25 = 0;
              if ( v17 )
              {
                v19 = (unsigned int *)(v16 + 184);
                v20 = v9 + 2;
                do
                {
                  v21 = *v20;
                  v20 += 18;
                  v26 = v20;
                  if ( !v21 )
                  {
                    memmove((int)&v31[2], (int)(v20 - 18), 0x48u);
                    v8 = IopConnectInterrupt(v19, v28, 0, v29, 0, a5, v12, 1, v24, (int)v31);
                    if ( v8 < 0 )
                      goto LABEL_27;
                    ++v6;
                    ++v19;
                    if ( v6 >= v11 )
                      break;
                    v18 = v25;
                    v20 = v26;
                  }
                  v22 = *v9;
                  v18 = (unsigned int *)((char *)v18 + 1);
                  v25 = v18;
                }
                while ( (unsigned int)v18 < v22 );
              }
              memmove((int)v30, *(_DWORD *)(v16 + 184) + 88, 0xB0u);
              __dmb(0xBu);
              memmove(v16, (int)v30, 0xB0u);
              *v27 = v16;
            }
            else
            {
              v8 = -1073741670;
            }
LABEL_27:
            ExFreePoolWithTag((unsigned int)v9);
            if ( v8 < 0 && v16 )
            {
              if ( v6 )
              {
                v23 = v16;
                do
                {
                  IoDisconnectInterrupt(*(_DWORD *)(v23 + 184) + 88);
                  v23 += 4;
                  --v6;
                }
                while ( v6 );
              }
              ExFreePoolWithTag(v16);
            }
            return v8;
          }
          if ( a6 >= v12 )
          {
            LOBYTE(v12) = a6;
            goto LABEL_18;
          }
        }
      }
      return sub_81A230();
    }
  }
  return v8;
}
