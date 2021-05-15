// BgpBcInitializeCriticalMode 
 
int __fastcall BgpBcInitializeCriticalMode(int a1, int a2)
{
  int v2; // r3
  unsigned __int16 *v4; // r5
  unsigned __int16 *v5; // r0
  unsigned __int16 *v6; // r0
  unsigned __int16 *v7; // r0
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r0
  unsigned __int16 *v10; // r0
  int v11; // r0
  int *v12; // r7
  int v13; // r8
  int v14; // r9
  int *v15; // r10
  unsigned __int16 *v16; // r7
  int v17; // r0
  unsigned __int16 *v18[2]; // [sp+8h] [bp-48h] BYREF
  unsigned __int16 *v19; // [sp+10h] [bp-40h] BYREF
  unsigned __int16 *v20; // [sp+14h] [bp-3Ch]
  unsigned __int16 *v21; // [sp+1Ch] [bp-34h] BYREF
  _DWORD v22[12]; // [sp+20h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 84);
  if ( (v2 & 0x400000) != 0 )
    return sub_975F50();
  if ( (v2 & 0x2000000) != 0 )
    BcpDisplayParameters = 1;
  v4 = 0;
  v19 = 0;
  v21 = 0;
  if ( a2 != -1 )
  {
    v5 = (unsigned __int16 *)BcpFindMessage(-1056931839);
    RtlInitUnicodeString((unsigned int)word_641610, v5);
    v6 = (unsigned __int16 *)BcpFindMessage(-1056931832);
    RtlInitUnicodeString((unsigned int)&unk_641620, v6);
    v7 = (unsigned __int16 *)BcpFindMessage(1090551817);
    RtlInitUnicodeString((unsigned int)&unk_641628, v7);
    v8 = (unsigned __int16 *)BcpFindMessage(1090551824);
    RtlInitUnicodeString((unsigned int)&unk_641630, v8);
    v9 = (unsigned __int16 *)BcpFindMessage(1090551825);
    RtlInitUnicodeString((unsigned int)&unk_641638, v9);
    v10 = (unsigned __int16 *)BcpFindMessage(-1056931837);
    RtlInitUnicodeString((unsigned int)word_641618, v10);
    if ( BcpGetProgressMessages(-1056931822, (int *)&v21, v18) >= 0 )
    {
      RtlInitUnicodeString((unsigned int)&unk_641640, v21);
      RtlInitUnicodeString((unsigned int)&unk_641648, v18[0]);
      v11 = BcpGetProgressMessages(-1056931821, (int *)&v19, v18);
      v4 = v19;
      if ( v11 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)&unk_641650, v19);
        RtlInitUnicodeString((unsigned int)&unk_641658, v18[0]);
        if ( *(_WORD *)BcpFindMessage(1090551814) == 48 )
          dword_619018 |= 0x20000u;
        v22[0] = -14653518;
        v22[1] = -1;
        v12 = dword_616150;
        v13 = 0;
LABEL_11:
        v14 = 0;
        v15 = v12;
        while ( BgpFoDetermineFontInformation(*v15) >= 0 )
        {
          ++v14;
          *v15++ = v22[3];
          if ( v14 >= 3 )
          {
            ++v13;
            v12 += 14;
            if ( v13 < 5 )
              goto LABEL_11;
            v22[4] = 0;
            if ( BcpGetMaxResourceProfile((int)v22, &v19) >= 0 )
            {
              v16 = v19;
              v17 = BgpFwAllocateMemory((unsigned int)v19);
              if ( v17 )
              {
                BcpWorkspace[0] = v17;
                BcpWorkspace[1] = v16;
                dword_618F58 = 0;
                v19 = v20;
                v20 = v18[1];
                dword_641660 = BgpDisplayCharacterGetContext((int)v22, (int)&v19, 3);
                if ( dword_641660 )
                {
                  dword_619018 |= 0x10u;
                  return 0;
                }
              }
            }
            break;
          }
        }
      }
    }
    if ( v21 )
      BgpFwFreeMemory((int)v21);
    if ( v4 )
      BgpFwFreeMemory((int)v4);
    if ( dword_641660 )
      BgpDisplayCharacterDestroyContext(dword_641660);
  }
  return 0;
}
