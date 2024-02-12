function char_a() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [0, -6]);
    capsule([4, -2], [4, -8]);
}

function char_b() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, 0], [0, -8]);
    capsule([4, -4], [4, -6]);
}

function char_c() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [0, -6]);
    sphere([4, -4]);
    sphere([4, -6]);
}

function char_d() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [0, -6]);
    capsule([4, 0], [4, -8]);
}

function char_e() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [0, -6]);
    capsule([0, -4.5], [4, -4.5]);
    capsule([4, -4.5], [4, -4]);
    sphere([4, -6]);
}

function char_f() {
    capsule([2, -2], [2, -8]);
    quarter0_torus([4, -2]);
    sphere([4, 0]);
    capsule([0, -4.5], [4, -4.5]);
}

function char_g() {
    torus([2, -4]);
    capsule([4, -2], [4, -6]);
    quarter3_torus([2, -6]);
    capsule([0, -8], [2, -8]);
}

function char_h() {
    half0_torus([2, -4]);
    capsule([0, 0], [0, -8]);
    capsule([4, -4], [4, -8]);
}

function char_i() {
    capsule([0, -2], [0, -8]);
    sphere([0, -0.5]);
}

function char_j() {
    half1_torus([2, -6]);
    capsule([4, -2], [4, -6]);
    sphere([4, -0.5]);
    sphere([0, -6]);
}

function char_k() {
    capsule([0, 0], [0, -8]);
    capsule([0, -6], [4, -4]);
    capsule([0, -6], [4, -8]);
}

function char_l() {
    capsule([0, 0], [0, -8]);
}

function char_m() {
    capsule([0, -2], [0, -8]);
    half0_torus([2, -4]);
    half0_torus([6, -4]);
    capsule([4, -4], [4, -8]);
    capsule([8, -4], [8, -8]);
    
}

function char_n() {
    half0_torus([2, -4]);
    capsule([0, -2], [0, -8]);
    capsule([4, -4], [4, -8]);
}

function char_o() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [0, -6]);
    capsule([4, -4], [4, -6]);
}

function char_p() {
    torus([2, -4]);
    capsule([0, -4], [0, -8]);
}

function char_q() {
    torus([2, -4]);
    capsule([4, -4], [4, -8]);
}

function char_r() {
    half0_torus([2, -4]);
    capsule([0, -2], [0, -8]);
    sphere([4, -4]);
}

function char_s() {
    half0_torus([2, -4]);
    half1_torus([2, -6]);
    capsule([0, -4], [4, -6]);
    sphere([0, -6]);
    sphere([4, -4]);
}

function char_t() {
    capsule([2, 0], [2, -8]);
    capsule([0, -2], [4, -2]);
}

function char_u() {
    half1_torus([2, -6]);
    capsule([4, -2], [4, -8]);
    capsule([0, -2], [0, -6]);
}

function char_v() {
    capsule([0, -2], [2, -8]);
    capsule([4, -2], [2, -8]);
}

function char_w() {
    capsule([0, -2], [2, -8]);
    capsule([4, -2], [2, -8]);
    capsule([4, -2], [6, -8]);
    capsule([8, -2], [6, -8]);
}

function char_x() {
    capsule([0, -2], [4, -8]);
    capsule([4, -2], [0, -8]);
}

function char_y() {
    half1_torus([2, -4]);
    capsule([4, -2], [4, -6]);
    capsule([0, -2], [0, -4]);
    quarter3_torus([2, -6]);
    capsule([0, -8], [2, -8]);
}

function char_z() {
    capsule([0, -2], [4, -2]);
    capsule([0, -8], [4, -8]);
    capsule([4, -2], [0, -8]);
}

function char_A() {
    half0_torus([2, -2]);
    capsule([0, -2], [0, -8]);
    capsule([4, -2], [4, -8]);
    capsule([0, -4], [4, -4]);
}

function char_B() {
    capsule([0, 0], [0, -8]);
    capsule([0, 0], [2, 0]);
    capsule([0, -4], [2, -4]);
    capsule([0, -8], [2, -8]);
    half3_torus([2, -2]);
    half3_torus([2, -6]);
}

function char_C() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    sphere([4, -2]);
    sphere([4, -6]);
}

function char_D() {
    capsule([0, 0], [0, -8]);
    capsule([4, -2], [4, -6]);
    quarter1_torus([2, -2]);
    quarter3_torus([2, -6]);
    capsule([0, 0], [2, 0]);
    capsule([0, -8], [2, -8]);
}

function char_E() {
    quarter0_torus([2, -2]);
    quarter2_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    capsule([0, -4], [4, -4]);
    capsule([2, 0], [4, 0]);
    capsule([2, -8], [4, -8]);
}

function char_F() {
    quarter0_torus([2, -2]);
    capsule([0, -2], [0, -8]);
    capsule([0, -4], [4, -4]);
    capsule([2, 0], [4, 0]);
}

function char_G() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    sphere([4, -2]);
    capsule([4, -4], [4, -6]);
    capsule([2, -4], [4, -4]);
}

function char_H() {
    capsule([0, 0], [0, -8]);
    capsule([4, 0], [4, -8]);
    capsule([0, -4], [4, -4]);
}

function char_I() {
    capsule([0, 0], [4, 0]);
    capsule([0, -8], [4, -8]);
    capsule([2, 0], [2, -8]);
}

function char_J() {
    half1_torus([2, -6]);
    capsule([0, 0], [4, 0]);
    capsule([4, 0], [4, -6]);
    sphere([0, -6]);
}

function char_K() {
    capsule([0, 0], [0, -8]);
    capsule([0, -4], [2, -4]);
    quarter1_torus([2, -6]);
    quarter3_torus([2, -2]);
    capsule([4, 0], [4, -2]);
    capsule([4, -6], [4, -8]);
}

function char_L() {
    quarter2_torus([2, -6]);
    capsule([0, 0], [0, -6]);
    sphere([0, -6]);
    capsule([2, -8], [4, -8]);
}

function char_M() {
    half0_torus([2, -2]);
    half0_torus([6, -2]);
    capsule([4, -2], [4, -8]);
    capsule([8, -2], [8, -8]);
    capsule([0, -2], [0, -8]);
}

function char_N() {
    capsule([0, 0], [0, -8]);
    capsule([4, 0], [4, -8]);
    capsule([0, 0], [4, -8]);
}

function char_O() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    capsule([4, -2], [4, -6]);
}

function char_P() {
    capsule([0, 0], [0, -8]);
    capsule([0, 0], [2, 0]);
    capsule([0, -4], [2, -4]);
    half3_torus([2, -2]);
}

function char_Q() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    capsule([4, -2], [4, -6]);
    capsule([2, -6], [4, -8]);
}

function char_R() {
    capsule([0, 0], [0, -8]);
    capsule([0, 0], [2, 0]);
    capsule([0, -4], [2, -4]);
    half3_torus([2, -2]);
    quarter1_torus([2, -6]);
    capsule([4, -6], [4, -8]);
}

function char_S() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    quarter2_torus([2, -2]);
    quarter1_torus([2, -6]);
    sphere([0, -6]);
    sphere([4, -2]);
}

function char_T() {
    capsule([0, 0], [4, 0]);
    capsule([2, 0], [2, -8]);
}

function char_U() {
    half1_torus([2, -6]);
    capsule([0, 0], [0, -6]);
    capsule([4, 0], [4, -6]);
}

function char_V() {
    capsule([0, 0], [2, -8]);
    capsule([4, 0], [2, -8]);
}

function char_W() {
    half1_torus([2, -6]);
    half1_torus([6, -6]);
    capsule([4, 0], [4, -6]);
    capsule([8, 0], [8, -6]);
    capsule([0, 0], [0, -6]);
}

function char_X() {
    capsule([0, 0], [4, -8]);
    capsule([4, 0], [0, -8]);
}

function char_Y() {
    capsule([0, 0], [0, -2]);
    capsule([4, 0], [4, -2]);
    half1_torus([2, -2]);
    capsule([2, -4], [2, -8]);
}

function char_Z() {
    capsule([0, 0], [4, 0]);
    capsule([0, -8], [4, -8]);
    capsule([4, 0], [0, -8]);
}

function char_0() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    capsule([4, -2], [4, -6]);
    capsule([4, -2], [0, -6]);
    sphere([4, -2]);
    sphere([4, -6]);
}

function char_1() {
    capsule([0, -8], [4, -8]);
    capsule([2, 0], [2, -8]);
    quarter0_torus([2, -2]);
    sphere([0, -2]);
}

function char_2() {
    capsule([0, -8], [4, -8]);
    capsule([0, -8], [4, -2]);
    half0_torus([2, -2]);
    sphere([0, -2]);
}

function char_3() {
    capsule([0, 0], [2, 0]);
    capsule([0, -4], [2, -4]);
    capsule([0, -8], [2, -8]);
    half3_torus([2, -2]);
    half3_torus([2, -6]);
}

function char_4() {
    capsule([4, 0], [4, -8]);
    capsule([0, 0], [0, -2]);
    capsule([2, -4], [4, -4]);
    quarter2_torus([2, -2]);
}

function char_5() {
    capsule([0, 0], [4, 0]);
    capsule([0, 0], [0, -4]);
    capsule([0, -4], [2, -4]);
    capsule([0, -8], [2, -8]);
    half3_torus([2, -6]);
}

function char_6() {
    half0_torus([2, -2]);
    half1_torus([2, -6]);
    half0_torus([2, -6]);
    capsule([0, -2], [0, -6]);
    sphere([4, -2]);
}

function char_7() {
    capsule([0, -8], [4, 0]);
    capsule([0, 0], [4, 0]);
}

function char_8() {
    torus([2, -2]);
    torus([2, -6]);
}

function char_9() {
    torus([2, -2]);
	capsule([4, -2], [4, -8]);
}

var letter = [];

function torus(pos) {
    letter.push([[pos[0]-2,pos[1]], [pos[0],pos[1]+2]]);
    letter.push([[pos[0],pos[1]+2], [pos[0]+2,pos[1]]]);
    letter.push([[pos[0]+2,pos[1]], [pos[0],pos[1]-2]]);
    letter.push([[pos[0],pos[1]-2], [pos[0]-2,pos[1]]]);
}

function half0_torus(pos) {
    letter.push([[pos[0]-2,pos[1]], [pos[0],pos[1]+2]]);
    letter.push([[pos[0],pos[1]+2], [pos[0]+2,pos[1]]]);
}

function half1_torus(pos) {
    letter.push([[pos[0]+2,pos[1]], [pos[0],pos[1]-2]]);
    letter.push([[pos[0],pos[1]-2], [pos[0]-2,pos[1]]]);
}

function half2_torus(pos) {
    letter.push([[pos[0]-2,pos[1]], [pos[0],pos[1]+2]]);
    letter.push([[pos[0],pos[1]-2], [pos[0]-2,pos[1]]]);
}

function half3_torus(pos) {
    letter.push([[pos[0],pos[1]+2], [pos[0]+2,pos[1]]]);
    letter.push([[pos[0]+2,pos[1]], [pos[0],pos[1]-2]]);
}

function quarter0_torus(pos) {
    letter.push([[pos[0]-2,pos[1]], [pos[0],pos[1]+2]]);
}

function quarter1_torus(pos) {
    letter.push([[pos[0],pos[1]+2], [pos[0]+2,pos[1]]]);
}

function quarter2_torus(pos) {
    letter.push([[pos[0],pos[1]-2], [pos[0]-2,pos[1]]]);
}

function quarter3_torus(pos) {
    letter.push([[pos[0]+2,pos[1]], [pos[0],pos[1]-2]]);
}

function capsule(a, b) {
    letter.push([a, b]);
}

function sphere(a) {
    letter.push([a, a]);
}

function cook() {
    var ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    var letters={};
    for (var c=0; c<ALPHABET.length; c++) {
        letter=[];
        window['char_'+ALPHABET[c]]();
        letters[ALPHABET[c]]=letter;
    }
    return letters;
}