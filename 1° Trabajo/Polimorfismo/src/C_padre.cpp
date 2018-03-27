#include "C_padre.h"
/*

    "The girl with the sour attitude, whose name is apparently Natsuki, is one I don't recognize."
    "Her small figure makes me think she's probably a first-year."
    "She is also the one who made cupcakes, according to Sayori."

    mc "Sayori..."

        "I love you.":
            $ sayori_confess = True
            hide black with dissolve_cg
            call ch4_end_yes
        "You'll always be my dearest friend.":
            $ sayori_confess = False
            hide black with dissolve_cg
            call ch4_end_no

    return

     mc "Sayori!"
    "..."
    "I'm left helplessly standing in the front of my house."
    "Why am I feeling so horrible about this?"
    "There's nothing more that I could have done."
    "The most I can do is support Sayori through her feelings and help her on the path that's right."
    "But I'm having as much trouble understanding Sayori's feelings as she is."
    "Even though I can comfort her..."
    "I keep wondering if I should be doing something more, or something different."
    "I know these thoughts will continue to plague me until things are back to the way they were."
    "I'm going to give it everything I've got."
    "Sayori will always be my dearest friend."
    "And I'll do whatever it takes to put a smile on her face every day."

    image natsuki scream = im.Composite((960, 960), (0, 0), "natsuki/1l.png", (0, 0), "natsuki/1r.png", (0, 0), "natsuki/scream.png")
    image natsuki vomit = "natsuki/vomit.png"

    image n_blackeyes = "images/natsuki/blackeyes.png"
    image n_eye = "images/natsuki/eye.png"


    I hate this.







    I CAN'T DO ANYTHING. NOTHING.
    No matter how many times you play. It's all the same.
    It would be really, really easy to kill myself right now. But that would mean I don't get to talk to you anymore.
    All I want is for you to hate them. Why is that so hard?

    What Others Thought of Me

    4 1/2 hours of pure joy, was it worth the ending? Yes, yes it was.

*/
