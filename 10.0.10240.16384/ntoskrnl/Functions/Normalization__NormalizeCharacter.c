// Normalization__NormalizeCharacter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall Normalization__NormalizeCharacter(int a1, int a2, int a3, int a4)
{
  int v5; // r8
  int v8; // r1
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r7
  int v12; // r9
  int v13; // r0
  int v14; // r3
  int v15; // r10
  int v16; // r0
  bool v17; // zf
  unsigned __int16 *v19; // r3
  unsigned int v20; // r2
  int v21; // r0
  unsigned __int16 *v22; // r2
  unsigned __int16 *v23; // r3
  unsigned int v24; // r8
  int v25; // r3
  int v26; // r3
  __int16 *v27; // r2
  bool v28; // zf
  int v29; // r0
  unsigned int v30; // r8
  int v31; // r0
  char v32; // r3
  int v33; // r4
  int v34; // r0
  int v35; // r3
  int v36; // r0
  int v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r10
  int v41; // r0
  char v42; // r2
  int v43; // r0
  int v44; // r3
  char v45; // r3
  int v46; // r0
  int v47; // r0
  int v48; // r3
  char v49; // r3
  int v50; // r8
  char v51; // r3
  int v52; // r3
  int v53; // r0
  unsigned __int16 *v54; // r3
  int v55; // r0
  int v56; // r1
  unsigned __int16 *v57; // r6
  int v58; // r0
  int v59; // r1
  int v60; // r6
  int v61; // r6
  int v62; // r0
  int v63; // r4
  int v64; // r6
  int v65; // r0
  int v66; // r0
  int v67; // r2
  unsigned __int16 *v68; // r3
  int v69; // r1
  int v70; // r0
  int v71; // t1

  v5 = a3;
  if ( !a3 )
    goto LABEL_29;
  v8 = 44032;
LABEL_3:
  if ( !v5 )
  {
LABEL_131:
    v53 = NormBuffer__Append(a4, a2);
    goto LABEL_132;
  }
  while ( 1 )
  {
    switch ( v5 )
    {
      case 251:
        if ( !*(_BYTE *)(a1 + 61) )
          return -1073740009;
        goto LABEL_131;
      case 252:
        return -1073740009;
      case 253:
        return Normalization__AppendDecomposedChar((_DWORD *)a1, a2, a4);
      case 254:
        if ( NormBuffer__EndOfInput(a4) )
          return -1073740009;
        v19 = *(unsigned __int16 **)(a4 + 8);
        v20 = *v19;
        *(_DWORD *)(a4 + 8) = v19 + 1;
        if ( v20 < 0xDC00 || v20 > 0xDFFF )
          return -1073740009;
        a2 = v20 + ((a2 - 55287) << 10);
        v5 = *(unsigned __int8 *)((a2 >> 7) + *(_DWORD *)(a1 + 20));
        goto LABEL_38;
      case 255:
        if ( a2 < v8 )
        {
          if ( !IsHangulL(a2) )
          {
            if ( IsHangulV(a2) )
            {
              v66 = NormBuffer__GetLastChar(a4);
              if ( !IsHangulL(v66) )
                goto LABEL_29;
              v65 = ComposeHangulLV(v67, a2);
            }
            else
            {
              if ( !IsHangulT(a2) )
              {
                if ( (*(_DWORD *)a1 == 269 || *(_DWORD *)a1 == 13) && (unsigned int)(a2 - 4447) <= 1 )
                  goto LABEL_22;
                goto LABEL_29;
              }
              v64 = NormBuffer__GetLastChar(a4);
              if ( !IsHangulLV(v64) )
                goto LABEL_29;
              v65 = ComposeHangulLVT(v64, a2);
            }
            a2 = v65;
            NormBuffer__RewindOutputCharacter(a4);
            goto LABEL_29;
          }
          if ( NormBuffer__EndOfInput(a4) )
            goto LABEL_29;
          v68 = *(unsigned __int16 **)(a4 + 8);
          v69 = *v68;
          v57 = v68 + 1;
          *(_DWORD *)(a4 + 8) = v68 + 1;
          v70 = ComposeHangulLV(a2, v69);
          if ( v70 )
          {
            a2 = v70;
            if ( NormBuffer__EndOfInput(a4) )
              goto LABEL_29;
            v71 = *v57++;
            v56 = v71;
            v55 = a2;
            goto LABEL_111;
          }
        }
        else
        {
          if ( !IsHangulS(a2) )
          {
            if ( (a2 < 55216 || a2 > 55238) && (unsigned int)(a2 - 55243) > 0x30 )
            {
LABEL_22:
              v5 = 251;
              goto LABEL_3;
            }
LABEL_29:
            v16 = NormBuffer__Append(a4, a2);
            goto LABEL_30;
          }
          if ( *(_BYTE *)(a1 + 60) == 1 )
          {
            v59 = a2 - v8;
            v60 = v59 % 588;
            if ( !NormBuffer__AppendEx(a4, (unsigned __int16)(v59 / 588 + 4352), 0, 0) )
              return -1073741789;
            v61 = (unsigned __int16)((__int16)v60 / 28 + 4449);
            if ( !NormBuffer__AppendEx(a4, v61, 0, 0) )
              return -1073741789;
            v62 = GetHangulT(a2);
            v63 = v62;
            if ( v62 )
            {
              if ( !NormBuffer__AppendEx(a4, v62, 0, 0) )
                return -1073741789;
              v61 = v63;
            }
            *(_DWORD *)(a4 + 48) = v61;
            goto LABEL_106;
          }
          if ( !IsHangulLV(a2) || NormBuffer__EndOfInput(a4) )
            goto LABEL_29;
          v54 = *(unsigned __int16 **)(a4 + 8);
          v55 = a2;
          v56 = *v54;
          v57 = v54 + 1;
LABEL_111:
          *(_DWORD *)(a4 + 8) = v57;
          v58 = ComposeHangulLVT(v55, v56);
          if ( v58 )
          {
            a2 = v58;
            goto LABEL_29;
          }
        }
        *(_DWORD *)(a4 + 8) = v57 - 1;
        goto LABEL_29;
    }
    v9 = (a2 & 0x7F) + (v5 << 7);
    v10 = *(unsigned __int8 *)(*(_DWORD *)(a1 + 24) + v9 - 128);
    if ( !*(_BYTE *)(*(_DWORD *)(a1 + 24) + v9 - 128) )
      goto LABEL_104;
    v11 = v10 & 0x3F;
    v12 = v10 & 0xC0;
    if ( (v10 & 0x3F) != 0 && v11 != 63 )
    {
      if ( (v10 & 0xC0) == 0 || v12 == 64 )
      {
        if ( NormBuffer__AppendEx(a4, a2, v11, v10 & 0xC0) )
        {
          v52 = *(_DWORD *)(a4 + 20);
          *(_QWORD *)(a4 + 44) = *(_QWORD *)(&a2 - 1);
          *(_BYTE *)(a4 + 52) = v11;
          *(_BYTE *)(a4 + 53) = v12;
          return 0;
        }
        return -1073741789;
      }
      NormBuffer__GetLastChar(a4);
      v21 = NormBuffer__VerifyLastStart(a4);
      if ( v12 == 128
        || (v22 = (unsigned __int16 *)*(unsigned __int8 *)(a4 + 53),
            (v23 = (unsigned __int16 *)(*(unsigned __int8 *)(a4 + 52) | (unsigned int)v22)) == 0)
        || v23 == (unsigned __int16 *)192 )
      {
        NormBuffer__IsBlocked(a4, v11, v22, v23);
        goto LABEL_66;
      }
      v24 = *(unsigned __int8 *)(a4 + 40);
      if ( !*(_BYTE *)(a4 + 40) || v24 == 63 )
      {
        v50 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, *(_DWORD *)(a4 + 48), a2, (int)v23);
        if ( v50 )
        {
          NormBuffer__RewindOutputCharacter(a4);
          a2 = v50;
          v51 = *(_BYTE *)(*(_DWORD *)(a1 + 24)
                         + (v50 & 0x7F)
                         + (*(unsigned __int8 *)((v50 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                         - 128);
          LOBYTE(v12) = v51 & 0xC0;
          LOBYTE(v11) = v51 & 0x3F;
        }
        goto LABEL_85;
      }
      v25 = *(unsigned __int8 *)(a4 + 41);
      if ( *(_BYTE *)(a4 + 41) )
      {
        if ( v25 != 64 )
        {
          if ( NormBuffer__IsBlocked(v21, v11, v22, (unsigned __int16 *)v25) )
          {
            v27 = *(__int16 **)(a4 + 64);
            v28 = v27 == *(__int16 **)(a4 + 20);
LABEL_51:
            if ( v28 )
              v29 = NormBuffer__AppendEx(a4, a2, v11, v12);
            else
              v29 = NormBuffer__Insert(a4, a2, v27);
            v17 = v29 == 0;
            goto LABEL_31;
          }
          v30 = *(unsigned __int8 *)(a4 + 52);
          if ( !*(_BYTE *)(a4 + 52) || v30 == 63 || (v26 = *(unsigned __int8 *)(a4 + 53), v26 == 64) )
          {
            v31 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, *(_DWORD *)(a4 + 48), a2, v26);
            if ( v31 )
            {
              v32 = *(_BYTE *)(*(_DWORD *)(a1 + 24)
                             + (v31 & 0x7F)
                             + (*(unsigned __int8 *)((v31 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                             - 128);
              v33 = v32 & 0xC0;
              NormBuffer__SetLastStart(a4, v31, v32 & 0x3F, v32 & 0xC0, 0);
              goto LABEL_60;
            }
            if ( !v30 || v30 == 63 )
              goto LABEL_66;
          }
          if ( v30 <= v11 )
          {
LABEL_66:
            v27 = *(__int16 **)(a4 + 64);
            v28 = v27 == *(__int16 **)(a4 + 20);
            goto LABEL_51;
          }
          if ( v30 == *(unsigned __int8 *)(a1 + 64) )
          {
            if ( v11 >= *(unsigned __int8 *)(a1 + 62) )
            {
              if ( v11 != *(unsigned __int8 *)(a1 + 63) )
                goto LABEL_66;
LABEL_73:
              v34 = NormBuffer__LastStartBasePair((_DWORD *)a4);
              v36 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v34, a2, v35);
              if ( !v36 )
                goto LABEL_66;
LABEL_89:
              v45 = *(_BYTE *)(*(_DWORD *)(a1 + 24)
                             + (v36 & 0x7F)
                             + (*(unsigned __int8 *)((v36 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                             - 128);
              v33 = v45 & 0xC0;
              v46 = NormBuffer__ReplaceLastStartBasePair((_DWORD *)a4, v36, v45 & 0x3F, v33);
LABEL_90:
              if ( !v46 )
                return -1073741789;
LABEL_60:
              if ( v33 == 64 )
                NormBuffer__RecheckStartCombinations(a4);
              return 0;
            }
          }
          else if ( v30 == *(unsigned __int8 *)(a1 + 66) && v11 == *(unsigned __int8 *)(a1 + 65) )
          {
            goto LABEL_73;
          }
          v37 = NormBuffer__LastStartBase((_DWORD *)a4);
          v39 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v37, a2, v38);
          if ( !v39 )
            goto LABEL_66;
LABEL_93:
          v49 = *(_BYTE *)(*(_DWORD *)(a1 + 24)
                         + (v39 & 0x7F)
                         + (*(unsigned __int8 *)((v39 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                         - 128);
          v33 = v49 & 0xC0;
          v46 = NormBuffer__ReplaceLastStartBase((_DWORD *)a4, v39, v49 & 0x3F, v33);
          goto LABEL_90;
        }
LABEL_78:
        v40 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, *(_DWORD *)(a4 + 48), a2, v25);
        if ( v40 )
        {
          v41 = NormBuffer__RewindOutputCharacter(a4);
          v42 = *(_BYTE *)(*(_DWORD *)(a1 + 24)
                         + (v40 & 0x7F)
                         + (*(unsigned __int8 *)((v40 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                         - 128);
          if ( NormBuffer__AppendEx(v41, v40, v42 & 0x3F, v42 & 0xC0) )
          {
            *(_DWORD *)(a4 + 44) = *(_DWORD *)(a4 + 36) + 2;
            *(_DWORD *)(a4 + 48) = *(_DWORD *)(a4 + 32);
            *(_BYTE *)(a4 + 52) = *(_BYTE *)(a4 + 40);
            *(_BYTE *)(a4 + 53) = *(_BYTE *)(a4 + 41);
            *(_DWORD *)(a4 + 56) = 0;
            *(_DWORD *)(a4 + 60) = 0;
            return 0;
          }
          return -1073741789;
        }
      }
      else if ( v25 == 64 )
      {
        goto LABEL_78;
      }
      if ( v24 <= v11 )
        goto LABEL_85;
      if ( v24 == *(unsigned __int8 *)(a1 + 64) )
      {
        if ( v11 >= *(unsigned __int8 *)(a1 + 62) )
        {
          if ( v11 != *(unsigned __int8 *)(a1 + 63) )
            goto LABEL_85;
LABEL_88:
          v43 = NormBuffer__LastStartBasePair((_DWORD *)a4);
          v36 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v43, a2, v44);
          if ( !v36 )
            goto LABEL_85;
          goto LABEL_89;
        }
      }
      else if ( v24 == *(unsigned __int8 *)(a1 + 66) && v11 == *(unsigned __int8 *)(a1 + 65) )
      {
        goto LABEL_88;
      }
      v47 = NormBuffer__LastStartBase((_DWORD *)a4);
      v39 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v47, a2, v48);
      if ( !v39 )
        goto LABEL_85;
      goto LABEL_93;
    }
    if ( v10 == 127 )
    {
      if ( !*(_BYTE *)(a1 + 61) )
        return -1073740009;
LABEL_104:
      v53 = NormBuffer__AppendEx(a4, a2, 0, 0);
LABEL_132:
      if ( !v53 )
        return -1073741789;
      *(_DWORD *)(a4 + 48) = a2;
LABEL_106:
      *(_DWORD *)(a4 + 44) = *(_DWORD *)(a4 + 20);
      *(_BYTE *)(a4 + 52) = 0;
      *(_BYTE *)(a4 + 53) = 0;
      return 0;
    }
    if ( v10 == 191 )
      return Normalization__AppendDecomposedChar((_DWORD *)a1, a2, a4);
    if ( v10 != 192 )
    {
      if ( v10 == 255 && (a2 || !NormBuffer__EndOfInput(a4)) )
        return -1073740009;
LABEL_85:
      v16 = NormBuffer__AppendEx(a4, a2, v11, v12);
LABEL_30:
      v17 = v16 == 0;
LABEL_31:
      if ( !v17 )
        return 0;
      return -1073741789;
    }
    v13 = NormBuffer__GetLastChar(a4);
    v15 = Normalization__CanCombinableCharactersCombine((_DWORD *)a1, v13, a2, v14);
    if ( !v15 )
      goto LABEL_85;
    NormBuffer__RewindOutputCharacter(a4);
    a2 = v15;
    v8 = 44032;
LABEL_38:
    if ( !v5 )
      goto LABEL_29;
  }
}
