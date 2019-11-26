const app = new Vue({
    el: '#app',
    data: {
        seconds: 0,
    },
    mounted: function () {
        this.$interval = setInterval(() => {
            this.seconds++;
        }, 1000);
    },

    destroyed: function () {
        clearInterval(this.$interval);
    },

    methods: {
        stopTimer: function () {
            clearInterval(this.$interval);
        }
    }
})