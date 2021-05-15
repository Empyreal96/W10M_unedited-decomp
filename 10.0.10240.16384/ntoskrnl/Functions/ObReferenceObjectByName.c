// ObReferenceObjectByName 
 
int __fastcall ObReferenceObjectByName(int a1, int a2, int *a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v11; // r4
  unsigned int *v12; // r6
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r2
  int v20; // r0
  int v22; // [sp+4h] [bp-1C4h]
  int v23; // [sp+8h] [bp-1C0h]
  int v24; // [sp+Ch] [bp-1BCh]
  int v25; // [sp+10h] [bp-1B8h]
  int v26; // [sp+14h] [bp-1B4h]
  int v27; // [sp+18h] [bp-1B0h]
  int v28; // [sp+1Ch] [bp-1ACh]
  int v29; // [sp+20h] [bp-1A8h] BYREF
  int v30; // [sp+24h] [bp-1A4h] BYREF
  int v31[2]; // [sp+28h] [bp-1A0h] BYREF
  int v32; // [sp+30h] [bp-198h] BYREF
  int v33; // [sp+34h] [bp-194h]
  int v34; // [sp+38h] [bp-190h]
  int v35; // [sp+3Ch] [bp-18Ch]
  int v36; // [sp+40h] [bp-188h]
  int v37; // [sp+44h] [bp-184h]
  int v38; // [sp+50h] [bp-178h]
  int *v39; // [sp+54h] [bp-174h]
  int v40; // [sp+58h] [bp-170h]
  char v41[120]; // [sp+68h] [bp-160h] BYREF
  char v42[232]; // [sp+E0h] [bp-E8h] BYREF

  if ( a1 )
  {
    v11 = ObpCaptureObjectName(a6, a1, v31, 1);
    if ( v11 < 0 )
      return v11;
    if ( LOWORD(v31[0]) )
    {
      if ( a3 || (a3 = (int *)v41, v11 = SeCreateAccessState(v41, v42, a4, a5 + 52), v11 >= 0) )
      {
        v11 = ObpLookupObjectName(0, v31, a2, a5, a6, a7, 0, 0, a3, &v32, &v29);
        v30 = v11;
        if ( BYTE2(v36) )
        {
          v12 = (unsigned int *)(v32 + 148);
          __pld((void *)(v32 + 148));
          v13 = *v12;
          if ( (*v12 & 0xFFFFFFF0) > 0x10 )
            v14 = v13 - 16;
          else
            v14 = 0;
          if ( (v13 & 2) != 0 )
            goto LABEL_30;
          __dmb(0xBu);
          do
            v15 = __ldrex(v12);
          while ( v15 == v13 && __strex(v14, v12) );
          if ( v15 != v13 )
LABEL_30:
            ExfReleasePushLock(v12, v13);
          KeAbPostRelease((unsigned int)v12);
          v37 = -286387660;
          v16 = ObfDereferenceObject(v32);
          v32 = 0;
          HIWORD(v36) = 0;
          v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v18 = *(_WORD *)(v17 + 0x134) + 1;
          *(_WORD *)(v17 + 308) = v18;
          if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
            KiCheckForKernelApcDelivery(v16);
        }
        if ( v33 )
        {
          ObfDereferenceObject(v33);
          v33 = 0;
        }
        *a8 = 0;
        if ( v11 >= 0 )
        {
          v19 = *(unsigned __int8 *)(v29 - 12);
          v40 = 0;
          v38 = ObTypeIndexTable[v19 ^ (unsigned __int8)((unsigned __int16)(v29 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
              + 8;
          v39 = v31;
          SeSetLearningModeObjectInformation();
          v20 = ObpCheckObjectReference(
                  v29,
                  a3,
                  (int)&v30,
                  a6,
                  (int)&v30,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31[0],
                  v31[1],
                  v32,
                  v33,
                  v34,
                  v35,
                  v36);
          if ( v20 )
            *a8 = v29;
          else
            v20 = PspDereferenceSiloObject(v29);
          SeClearLearningModeObjectInformation(v20);
          v11 = v30;
        }
        if ( a3 == (int *)v41 )
        {
          SepDeleteAccessState((int)a3);
          SeReleaseSubjectContext(a3 + 7);
        }
      }
      ObpFreeObjectNameBuffer(v31);
      return v11;
    }
  }
  return sub_7C4F28();
}
