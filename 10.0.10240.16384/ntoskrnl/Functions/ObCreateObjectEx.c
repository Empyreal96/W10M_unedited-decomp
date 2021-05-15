// ObCreateObjectEx 
 
int __fastcall ObCreateObjectEx(char a1, _DWORD *a2, int a3, char a4, int a5, int a6, int a7, int a8, _DWORD *a9, int a10)
{
  int v10; // r8
  int v13; // r10
  unsigned int v14; // r4
  unsigned int v15; // r6
  int v16; // r9
  int v17; // r4
  int result; // r0
  int v19; // r3
  int v20; // r2
  int v21; // r5
  unsigned int v22; // r4
  int v23; // r9
  __int64 v24; // kr00_8
  int v25; // r0
  unsigned int v26; // r0
  unsigned int v27; // r3
  int v28; // r6
  unsigned int v29; // r2
  unsigned int v30; // r2
  unsigned int v31; // [sp+10h] [bp-30h] BYREF
  char v32[4]; // [sp+18h] [bp-28h] BYREF
  int v33; // [sp+1Ch] [bp-24h]

  v10 = a4;
  v13 = a1;
  v14 = (unsigned int)KeGetPcr();
  v15 = (v14 & 0xFFFFF000) + 1408;
  v16 = *(_DWORD *)((v14 & 0xFFFFF000) + 0xB20);
  ++*(_DWORD *)(v16 + 12);
  v17 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v16);
  if ( !v17 )
  {
    ++*(_DWORD *)(v16 + 16);
    v23 = *(_DWORD *)(v15 + 1444);
    ++*(_DWORD *)(v23 + 12);
    v17 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v23);
    if ( !v17 )
    {
      v24 = *(_QWORD *)(v23 + 32);
      v25 = *(_DWORD *)(v23 + 28);
      ++*(_DWORD *)(v23 + 16);
      v17 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v23 + 40))(v25, HIDWORD(v24), v24);
      if ( !v17 )
        return -1073741670;
    }
  }
  *(_DWORD *)v17 = *(_DWORD *)(v15 + 20);
  if ( ObpCaptureObjectCreateInformation(v13, v10, a3, v32, v17, 0) < 0 )
    return sub_7FF320();
  if ( (*(_DWORD *)v17 & a2[12]) != 0 )
  {
    v21 = -1073741811;
  }
  else if ( (*(_DWORD *)v17 & 0x10) == 0
         || SeSinglePrivilegeCheck(SeCreatePermanentPrivilege, dword_9227A4, v13, (int)&SeCreatePermanentPrivilege) )
  {
    v19 = a7;
    if ( !a7 )
      v19 = a2[20];
    v20 = a8;
    if ( !a8 )
      v20 = a2[21];
    *(_DWORD *)(v17 + 12) = v19;
    *(_DWORD *)(v17 + 16) = v20;
    v21 = ObpAllocateObject(v17, v10, a2, v32, a6, &v31, a10);
    if ( v21 >= 0 )
    {
      v22 = v31;
      if ( ObpTraceFlags )
      {
        ObpRegisterObject(v31);
        ObpPushStackInfo(v22, 1, 1u, 1953261124);
      }
      result = v21;
      *a9 = v22 + 24;
      return result;
    }
  }
  else
  {
    v21 = -1073741727;
  }
  if ( v33 )
    ObpFreeObjectNameBuffer((int)v32);
  v26 = *(_DWORD *)(v17 + 24);
  if ( v26 )
  {
    SeReleaseSecurityDescriptor(v26, *(_BYTE *)(v17 + 8), 1);
    *(_DWORD *)(v17 + 24) = 0;
  }
  v27 = (unsigned int)KeGetPcr();
  v28 = *(_DWORD *)((v27 & 0xFFFFF000) + 0xB20);
  v29 = *(unsigned __int16 *)(v28 + 8);
  ++*(_DWORD *)(v28 + 20);
  if ( *(unsigned __int16 *)(v28 + 4) < v29
    || (++*(_DWORD *)(v28 + 24),
        v28 = *(_DWORD *)((v27 & 0xFFFFF000) + 0xB24),
        v30 = *(unsigned __int16 *)(v28 + 8),
        ++*(_DWORD *)(v28 + 20),
        *(unsigned __int16 *)(v28 + 4) < v30) )
  {
    RtlpInterlockedPushEntrySList((unsigned __int64 *)v28, (_DWORD *)v17);
  }
  else
  {
    ++*(_DWORD *)(v28 + 24);
    (*(void (__fastcall **)(int))(v28 + 44))(v17);
  }
  return v21;
}
