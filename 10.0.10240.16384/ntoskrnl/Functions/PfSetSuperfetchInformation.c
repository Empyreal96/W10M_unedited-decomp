// PfSetSuperfetchInformation 
 
int __fastcall PfSetSuperfetchInformation(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v7; // r6
  int v8; // r4
  int v9; // r0
  int v10; // r0
  unsigned int v11; // r3
  int v12; // r8
  unsigned int v13; // r9
  unsigned int v14; // r3
  unsigned int v15; // r3
  int v16; // r0
  int v17; // r1
  int v18; // r2
  unsigned int v19; // r8
  int v20; // r9
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r1
  int v31; // [sp+Ch] [bp-4Ch] BYREF
  unsigned int v32; // [sp+10h] [bp-48h] BYREF
  unsigned int v33; // [sp+14h] [bp-44h]
  int v34; // [sp+18h] [bp-40h]
  int v35; // [sp+20h] [bp-38h] BYREF
  int v36; // [sp+24h] [bp-34h]
  int v37; // [sp+28h] [bp-30h]
  int v38; // [sp+2Ch] [bp-2Ch]
  int v39; // [sp+30h] [bp-28h]
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v7 = 0;
  v32 = 0;
  v33 = 0;
  if ( SeSinglePrivilegeCheck(SeProfileSingleProcessPrivilege, dword_922B94, (char)a4, 0) )
  {
    if ( a3 == 20 )
    {
      v35 = 0;
      v36 = 0;
      v37 = 0;
      v38 = 0;
      v39 = 0;
      v9 = memmove((int)&v35, a2, 0x14u);
      if ( v35 == 45 && v36 == 1802856515 )
      {
        switch ( v37 )
        {
          case 3:
            if ( v39 != 8 )
              goto LABEL_11;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v11 = *(_DWORD *)v38;
            v32 = *(_DWORD *)v38;
            v33 = *(_DWORD *)(v38 + 4);
            v12 = v33;
            if ( !v33 )
              goto LABEL_110;
            v13 = v11 >> 7;
            if ( !(v11 >> 7) )
              goto LABEL_110;
            v14 = v11 & 0x1F;
            if ( v14 < 2 )
              goto LABEL_35;
            if ( v14 <= 3 )
            {
              v15 = 36;
            }
            else if ( v14 == 5 )
            {
              v15 = 12;
            }
            else
            {
              if ( v14 != 27 )
              {
LABEL_35:
                v8 = -1073741637;
                break;
              }
              v15 = 8;
            }
            if ( v13 < v15 || v13 >= 0xFF8 )
              goto LABEL_110;
            v16 = ExAllocatePoolWithTag(1, v13, 1145398864);
            v7 = v16;
            if ( v16 )
            {
              if ( v4 )
              {
                if ( (v33 & 1) != 0 )
                  ExRaiseDatatypeMisalignment(v16);
                if ( v13 + v33 > MmUserProbeAddress || v13 + v33 < v33 )
                  *(_BYTE *)MmUserProbeAddress = 0;
              }
              memmove(v16, v12, v13);
              v33 = v7;
              v10 = PfpLogEventRequest(&v32);
              goto LABEL_9;
            }
            v8 = -1073741670;
            break;
          case 4:
            PfGenerateTrace(&dword_643940, 0);
            goto LABEL_37;
          case 5:
            v10 = PfpPrefetchRequest(&v35, v4);
            goto LABEL_9;
          case 7:
          case 22:
            v10 = PfpPfnPrioRequest(&v35, v4, &v32);
            goto LABEL_9;
          case 10:
            if ( v39 != 24 )
              goto LABEL_11;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            memmove((int)&v35, v38, 0x18u);
            v10 = PfpProcessScenarioPhase(&v35, v4);
            goto LABEL_9;
          case 11:
            if ( v39 != 4 )
              goto LABEL_11;
            v32 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v32 = *(_DWORD *)v38;
            if ( PfTSetTraceWorkerPriority(v32) <= 31 )
LABEL_37:
              v8 = 0;
            else
              v8 = -1073741431;
            break;
          case 13:
            if ( v39 != 8 )
              goto LABEL_11;
            v32 = 0;
            v33 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v32 = *(_DWORD *)v38;
            v17 = *(_DWORD *)(v38 + 4);
            v33 = v17;
            if ( (unsigned __int16)v32 != 1 || (unsigned int)(v17 - 1) > 4 )
              goto LABEL_110;
            if ( (v32 & 0x10000) != 0 )
              v18 = 2;
            else
              v18 = 1;
            v10 = PfpScenCtxPrefetchStateSet((unsigned int)&unk_637290, v17, v18, 0);
LABEL_9:
            v8 = v10;
            break;
          case 14:
            v10 = PfpRpControlRequest(&v35, v4);
            goto LABEL_9;
          case 15:
            if ( v39 != 4 )
              goto LABEL_11;
            v32 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v32 = *(_DWORD *)v38;
            v31 = dword_63728C + v32;
            v8 = PfpSetParameter(dword_6370A4, L"BaseTime", v32, &v31, 4);
            if ( v8 >= 0 )
              dword_63728C = v31;
            break;
          case 18:
            if ( v39 != 12 )
              goto LABEL_11;
            v32 = 0;
            v33 = 0;
            v34 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v38);
            v32 = *(_DWORD *)v38;
            v19 = *(_DWORD *)(v38 + 4);
            v33 = v19;
            v20 = *(_DWORD *)(v38 + 8);
            v34 = v20;
            if ( v32 != 2 || v19 >= 2 || (v20 & 0xFFFFFFFC) != 0 )
              goto LABEL_110;
            v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v21 + 308);
            v22 = KeAbPreAcquire((unsigned int)&PfTGlobals, 0, 0);
            v23 = v22;
            do
              v24 = __ldrex((unsigned __int8 *)&PfTGlobals);
            while ( __strex(v24 | 1, (unsigned __int8 *)&PfTGlobals) );
            __dmb(0xBu);
            if ( (v24 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(&PfTGlobals, v22, (unsigned int)&PfTGlobals);
            if ( v23 )
              *(_BYTE *)(v23 + 14) |= 1u;
            if ( v19 )
            {
              PfTCleanup(&PfTGlobals);
              PfTInitialize(&PfTGlobals);
            }
            v8 = PfTStart(&PfTGlobals);
            __dmb(0xBu);
            do
              v25 = __ldrex(&PfTGlobals);
            while ( __strex(v25 - 1, &PfTGlobals) );
            if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
              ExfTryToWakePushLock(&PfTGlobals);
            v26 = KeAbPostRelease((unsigned int)&PfTGlobals);
            v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v28 = *(_WORD *)(v27 + 0x134) + 1;
            *(_WORD *)(v27 + 308) = v28;
            if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
              KiCheckForKernelApcDelivery(v26);
            PfpScenCtxServiceThreadSet((unsigned int)&unk_637290, v19 == 0);
            break;
          case 19:
            if ( v39 != 12 )
              goto LABEL_11;
            v8 = 0;
            v32 = 0;
            v33 = 0;
            v34 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v32 = *(_DWORD *)v38;
            v29 = *(_DWORD *)(v38 + 4);
            v33 = v29;
            v34 = *(_DWORD *)(v38 + 8);
            if ( v32 != 2 || v29 >= 5 || (unsigned __int8)v34 > 7u || BYTE1(v34) > 7u || HIWORD(v34) )
              goto LABEL_110;
            MmSetTrimWhileAgingState();
            break;
          case 25:
            if ( v39 != 8 )
            {
LABEL_11:
              v8 = -1073741306;
              break;
            }
            v8 = 0;
            v32 = 0;
            v33 = 0;
            if ( v4 && (v38 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v9);
            v32 = *(_DWORD *)v38;
            v33 = *(_DWORD *)(v38 + 4);
            if ( v32 != 1 )
              goto LABEL_110;
            MmSetMinimumAgeRate();
            break;
          case 26:
            v10 = PfpDeprioritizeOldPagesInWs(&v35, v4);
            goto LABEL_9;
          default:
            v8 = -1073741821;
            break;
        }
      }
      else
      {
LABEL_110:
        v8 = -1073741811;
      }
    }
    else
    {
      v8 = -1073741820;
    }
  }
  else
  {
    v8 = -1073741790;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
